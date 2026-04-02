// ============================================================
// node.h — Definisi struct Node untuk Singly Linked List
// ENEE602004 Algoritma Pemrograman dan Praktikum
// ============================================================
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Setiap node menyimpan satu nilai (data) dan pointer ke node berikutnya.
// Jika next == nullptr, node ini adalah node terakhir dalam list.
struct Node {
    int   data;   // nilai yang disimpan
    Node* next;   // pointer ke node selanjutnya (nullptr = akhir list)

    // Constructor: inisialisasi data, set next = nullptr
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi pembantu: cetak judul seksi dengan garis pemisah
inline void section(const string& t) {
    int fill = max(0, 55 - (int)t.size());
    cout << "\n" << t << " " << string(fill, '-') << endl;
}
