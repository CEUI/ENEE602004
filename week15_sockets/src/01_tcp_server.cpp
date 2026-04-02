// 01_tcp_server.cpp — TCP echo server (POSIX socket, Linux/WSL)
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo01 src/01_tcp_server.cpp
// Run:     ./demo01             (terminal 1 -- server menunggu koneksi)
// Test:    echo "halo" | nc localhost 8080   (terminal 2)
#include "socket_utils.h"

int main() {
    cout << "TCP Echo Server -- port " << PORT << endl;

    // ── Langkah 1: Buat socket ────────────────────────────────
    // AF_INET    = IPv4
    // SOCK_STREAM = TCP (koneksi, andal, urut)
    // 0          = protokol default untuk SOCK_STREAM
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) { perror("socket"); return 1; }

    // Izinkan reuse alamat (hindari "Address already in use" saat restart)
    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // ── Langkah 2: Bind ke IP + port ─────────────────────────
    sockaddr_in addr{};
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(PORT);    // konversi byte order host -> network
    addr.sin_addr.s_addr = INADDR_ANY;     // terima dari semua interface

    if (bind(serverFd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); return 1;
    }

    // ── Langkah 3: Listen — tandai socket sebagai pasif ───────
    // backlog=5: maksimal 5 koneksi antre menunggu accept()
    if (listen(serverFd, 5) < 0) { perror("listen"); return 1; }
    cout << "Listening on 0.0.0.0:" << PORT << " ..." << endl;

    // ── Langkah 4: Accept loop — terima koneksi client ────────
    while (true) {
        sockaddr_in clientAddr{};
        socklen_t   clientLen = sizeof(clientAddr);

        // accept() memblokir sampai ada client yang konek
        int clientFd = accept(serverFd, (sockaddr*)&clientAddr, &clientLen);
        if (clientFd < 0) { perror("accept"); continue; }

        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, sizeof(clientIP));
        cout << "Client terhubung: " << clientIP << ":"
             << ntohs(clientAddr.sin_port) << endl;

        // ── Langkah 5: Terima dan echo data kembali ──────────
        char buf[BUFSIZE];
        while (true) {
            memset(buf, 0, sizeof(buf));
            int n = recv(clientFd, buf, sizeof(buf) - 1, 0); // baca data
            if (n <= 0) { cout << "Client terputus." << endl; break; }
            cout << "Diterima (" << n << " byte): " << buf;
            send(clientFd, buf, n, 0); // kirim balik (echo)
        }
        close(clientFd); // tutup koneksi client ini
    }

    close(serverFd);
    return 0;
}
