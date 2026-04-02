// 04_ee_sensor_server.cpp — aplikasi EE: sensor data server
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Server menerima ID channel sensor, membalas dengan pembacaan simulasi.
// Protokol: client kirim "0\n" -> server balas "CH0:3.14V\n"
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo04 src/04_ee_sensor_server.cpp
// Run:     ./demo04
// Test:    echo "0" | nc localhost 8080
//          echo "2" | nc localhost 8080
#include "socket_utils.h"
#include <cstdlib>  // atoi

// ── Data sensor simulasi (6 channel) ─────────────────────────
// Dalam sistem nyata: baca dari ADC, I2C, SPI, dll.
static double readSensor(int channel) {
    double base[] = {3.14, 1.80, 2.50, 0.75, 5.00, 1.23};
    if (channel < 0 || channel >= 6) return -1.0;
    return base[channel];  // nilai tetap (simulasi)
}

int main() {
    cout << "EE Sensor Data Server -- port " << PORT << endl;
    cout << "Channel tersedia: CH0..CH5" << endl;
    cout << "Test: echo \"0\" | nc localhost " << PORT << endl;

    // ── Buat dan konfigurasi TCP socket ──────────────────────
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) { perror("socket"); return 1; }
    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverFd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); return 1;
    }
    if (listen(serverFd, 5) < 0) { perror("listen"); return 1; }
    cout << "Menunggu koneksi sensor client..." << endl;

    // ── Accept loop ────────────────────────────────────────────
    while (true) {
        sockaddr_in clientAddr{};
        socklen_t   clientLen = sizeof(clientAddr);
        int clientFd = accept(serverFd, (sockaddr*)&clientAddr, &clientLen);
        if (clientFd < 0) { perror("accept"); continue; }

        // Baca request: ID channel dari client
        char buf[BUFSIZE];
        memset(buf, 0, sizeof(buf));
        int n = recv(clientFd, buf, sizeof(buf) - 1, 0);
        if (n > 0) {
            int ch = atoi(buf);     // parse nomor channel
            double val = readSensor(ch);

            // Bangun respons terstruktur: "CH<id>:<value>V\n"
            string resp;
            if (val < 0)
                resp = "ERROR:invalid_channel\n";
            else {
                char tmp[64];
                snprintf(tmp, sizeof(tmp), "CH%d:%.2fV\n", ch, val);
                resp = tmp;
            }
            cout << "  Client minta CH" << ch << " -> " << resp;
            send(clientFd, resp.c_str(), resp.size(), 0);
        }
        close(clientFd);
    }

    close(serverFd);
    return 0;
}
