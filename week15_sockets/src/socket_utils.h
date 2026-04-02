// socket_utils.h — header umum untuk socket programming
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Catatan: hanya untuk Linux/WSL (POSIX socket API)
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

const int PORT    = 8080;   // port default untuk semua demo
const int BUFSIZE = 1024;   // ukuran buffer baca/tulis

// Helper: cetak header section dengan garis pemisah
inline void section(const string& t) {
    int fill = max(0, 55 - (int)t.size());
    cout << "\n" << t << " " << string(fill, '-') << endl;
}
