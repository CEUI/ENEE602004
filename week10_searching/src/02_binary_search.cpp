// 02_binary_search.cpp — demo binary search dengan trace langkah
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo02 src/search_ops.cpp src/02_binary_search.cpp
// Run:     ./demo02
#include "search_ops.h"

int main() {
    cout << "==========================================\n";
    cout << " Demo 02: Binary Search — O(log n)       \n";
    cout << "==========================================\n";

    // Data ADC sensor — harus diurutkan terlebih dahulu
    vector<int> sensorData = {312, 876, 145, 654, 423, 789, 234, 567, 901, 111};

    section("Data Awal (tidak terurut)");
    cout << "  [ ";
    for (int v : sensorData) cout << v << " ";
    cout << "]\n";

    // Urutkan data sebelum binary search
    vector<int> sorted = sensorData;
    sort(sorted.begin(), sorted.end());

    section("Data Setelah Diurutkan");
    cout << "  [ ";
    for (int v : sorted) cout << v << " ";
    cout << "]\n";

    section("Pencarian Binary");
    // Kasus 1: elemen ada
    int idx = binarySearch(sorted, 567);
    cout << "  binarySearch(567): ";
    if (idx != -1) cout << "ditemukan di index " << idx << "\n";
    else           cout << "tidak ditemukan\n";

    // Kasus 2: elemen tidak ada
    idx = binarySearch(sorted, 999);
    cout << "  binarySearch(999): ";
    if (idx != -1) cout << "ditemukan di index " << idx << "\n";
    else           cout << "tidak ditemukan\n";

    section("Trace Langkah Demi Langkah — target=423");
    binarySearchTrace(sorted, 423);

    section("Trace Langkah Demi Langkah — target=500 (tidak ada)");
    binarySearchTrace(sorted, 500);

    section("Catatan");
    cout << "  - Binary search MEMERLUKAN data terurut\n";
    cout << "  - Kompleksitas waktu: O(log n)\n";
    cout << "  - n=1.000.000 hanya butuh ~20 langkah\n";

    cout << "\n  Selesai.\n";
    return 0;
}
