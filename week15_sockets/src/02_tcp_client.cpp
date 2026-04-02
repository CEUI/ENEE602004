// 02_tcp_client.cpp — TCP client (POSIX socket, Linux/WSL)
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo02 src/02_tcp_client.cpp
// Run:     ./demo01   (jalankan server dulu di terminal lain)
//          ./demo02   (lalu jalankan client ini)
#include "socket_utils.h"

const char* SERVER_IP = "127.0.0.1";  // localhost

int main() {
    cout << "TCP Client -- menghubungi " << SERVER_IP << ":" << PORT << endl;

    // ── Langkah 1: Buat TCP socket ────────────────────────────
    // Sama seperti server: AF_INET + SOCK_STREAM
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    // ── Langkah 2: Isi alamat server ─────────────────────────
    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port   = htons(PORT);
    // Konversi string "127.0.0.1" ke binary IP
    if (inet_pton(AF_INET, SERVER_IP, &server.sin_addr) <= 0) {
        cout << "Alamat tidak valid" << endl; return 1;
    }

    // ── Langkah 3: Connect ke server ─────────────────────────
    // TCP 3-way handshake terjadi di sini: SYN -> SYN-ACK -> ACK
    if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect"); return 1;
    }
    cout << "Terhubung! Ketik pesan (Ctrl+D atau baris kosong untuk keluar):" << endl;

    // ── Langkah 4: Kirim dan terima data ─────────────────────
    string input;
    char   buf[BUFSIZE];

    while (true) {
        cout << "> ";
        if (!getline(cin, input) || input.empty()) break;

        input += "\n";  // tambahkan newline sebagai penanda akhir pesan
        send(sock, input.c_str(), input.size(), 0);  // kirim ke server

        // Terima echo kembali dari server
        memset(buf, 0, sizeof(buf));
        int n = recv(sock, buf, sizeof(buf) - 1, 0);
        if (n <= 0) { cout << "Server menutup koneksi." << endl; break; }
        cout << "Echo: " << buf;
    }

    // ── Langkah 5: Tutup koneksi ──────────────────────────────
    close(sock);
    cout << "Terputus." << endl;
    return 0;
}
