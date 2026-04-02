// 01_linear_search.cpp — demo linear search pada data sensor
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo01 src/search_ops.cpp src/01_linear_search.cpp
// Run:     ./demo01
#include "search_ops.h"

int main() {
    cout << "==========================================\n";
    cout << " Demo 01: Linear Search — O(n)           \n";
    cout << "==========================================\n";

    // Data ADC sensor tidak terurut (12-bit, nilai 0-4095)
    vector<int> sensorData = {312, 876, 145, 654, 423, 789, 234, 567, 901, 111};

    section("Data Sensor (tidak terurut)");
    cout << "  [ ";
    for (int v : sensorData) cout << v << " ";
    cout << "]\n";

    section("Pencarian Linear");
    // Kasus 1: elemen ada dalam array
    int target = 654;
    int idx = linearSearch(sensorData, target);
    cout << "  linearSearch(" << target << "): ";
    if (idx != -1) cout << "ditemukan di index " << idx << "\n";
    else           cout << "tidak ditemukan\n";

    // Kasus 2: elemen tidak ada dalam array
    idx = linearSearch(sensorData, 999);
    cout << "  linearSearch(999): ";
    if (idx != -1) cout << "ditemukan di index " << idx << "\n";
    else           cout << "tidak ditemukan\n";

    // Kasus 3: elemen pertama
    idx = linearSearch(sensorData, 312);
    cout << "  linearSearch(312): ";
    if (idx != -1) cout << "ditemukan di index " << idx << " (elemen pertama)\n";
    else           cout << "tidak ditemukan\n";

    section("Catatan");
    cout << "  - Linear search bekerja pada data TIDAK terurut\n";
    cout << "  - Kompleksitas waktu: O(n)\n";
    cout << "  - Kasus terbaik : O(1) — target di index 0\n";
    cout << "  - Kasus terburuk: O(n) — target di akhir atau tidak ada\n";

    cout << "\n  Selesai.\n";
    return 0;
}
