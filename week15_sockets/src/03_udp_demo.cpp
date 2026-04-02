// 03_udp_demo.cpp — UDP demo: proses tunggal kirim ke dirinya sendiri
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// UDP = User Datagram Protocol: connectionless, tidak ada ACK, lebih cepat
// Demo ini: satu proses bind + sendto (ke 127.0.0.1) + recvfrom
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo03 src/03_udp_demo.cpp
// Run:     ./demo03
#include "socket_utils.h"
#include <sys/time.h>   // timeval untuk SO_RCVTIMEO

const int UDP_PORT = 9090;  // port berbeda dari demo TCP

int main() {
    cout << "=== Demo 03: UDP Connectionless ===" << endl;

    // ── Buat UDP socket ───────────────────────────────────────
    // SOCK_DGRAM = UDP (datagram, tanpa koneksi)
    int sockFd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockFd < 0) { perror("socket"); return 1; }

    // ── Set timeout recv agar tidak memblokir selamanya ───────
    struct timeval tv;
    tv.tv_sec = 2; tv.tv_usec = 0;  // timeout 2 detik
    setsockopt(sockFd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    // ── Bind ke port lokal (penerima) ─────────────────────────
    sockaddr_in bindAddr{};
    bindAddr.sin_family      = AF_INET;
    bindAddr.sin_port        = htons(UDP_PORT);
    bindAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockFd, (sockaddr*)&bindAddr, sizeof(bindAddr)) < 0) {
        perror("bind"); close(sockFd); return 1;
    }
    cout << "Bound ke UDP port " << UDP_PORT << endl;

    // ── Alamat tujuan: 127.0.0.1 (diri sendiri) ──────────────
    sockaddr_in destAddr{};
    destAddr.sin_family = AF_INET;
    destAddr.sin_port   = htons(UDP_PORT);
    inet_pton(AF_INET, "127.0.0.1", &destAddr.sin_addr);

    // ── Kirim beberapa datagram ────────────────────────────────
    section("Mengirim UDP datagram");
    const char* messages[] = {"Halo UDP!", "Sensor=3.14V", "Paket ke-3"};
    for (const char* msg : messages) {
        // sendto: kirim datagram tanpa koneksi -- langsung tuju alamat
        int sent = sendto(sockFd, msg, strlen(msg), 0,
                          (sockaddr*)&destAddr, sizeof(destAddr));
        cout << "  Terkirim " << sent << " byte: \"" << msg << "\"" << endl;
    }

    // ── Terima datagram yang dikirim ──────────────────────────
    section("Menerima UDP datagram");
    char buf[BUFSIZE];
    sockaddr_in fromAddr{};
    socklen_t   fromLen = sizeof(fromAddr);
    for (int i = 0; i < 3; i++) {
        memset(buf, 0, sizeof(buf));
        // recvfrom: terima datagram + catat alamat pengirim
        int n = recvfrom(sockFd, buf, sizeof(buf)-1, 0,
                         (sockaddr*)&fromAddr, &fromLen);
        if (n < 0) { cout << "  Timeout / error." << endl; break; }
        char fromIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &fromAddr.sin_addr, fromIP, sizeof(fromIP));
        cout << "  Diterima dari " << fromIP << ":"
             << ntohs(fromAddr.sin_port) << " -- \"" << buf << "\"" << endl;
    }

    close(sockFd);
    cout << "\nUDP tidak butuh connect/disconnect -- selesai!" << endl;
    return 0;
}
