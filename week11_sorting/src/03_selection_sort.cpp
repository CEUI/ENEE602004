// 03_selection_sort.cpp — demo selection sort, jumlah swap minimal
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo03 src/sort_ops.cpp src/03_selection_sort.cpp
// Run:     ./demo03
#include "sort_ops.h"

int main() {
    cout << "==========================================\n";
    cout << " Demo 03: Selection Sort — O(n^2)        \n";
    cout << "==========================================\n";

    section("Selection Sort dengan Hitung Swap");
    vector<int> data = {64, 25, 12, 22, 11, 45, 33, 8, 90, 17};
    printVec("Sebelum", data);

    // Hitung swap secara manual untuk demonstrasi
    int n = data.size();
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (data[j] < data[min_idx]) min_idx = j;
        if (min_idx != i) {
            swap(data[i], data[min_idx]);
            swapCount++;
        }
    }
    printVec("Sesudah", data);
    cout << "  Total swap: " << swapCount
         << " dari maksimum n-1=" << n - 1 << "\n";

    section("Mengapa Swap Minimal Penting untuk Flash Memory?");
    cout << "  - Flash/EEPROM: setiap write mengurangi masa pakai sel\n";
    cout << "  - Selection sort menjamin maksimum (n-1) write\n";
    cout << "  - Bubble sort & insertion sort bisa O(n^2) write\n";
    cout << "  - Contoh: ATmega EEPROM = 100.000 write cycle per byte\n";

    section("Demo dengan Data Sensor Tegangan");
    vector<int> voltage_mv = {3200, 1500, 4800, 2100, 3900, 700};
    printVec("Tegangan (mV) asal", voltage_mv);
    selectionSort(voltage_mv);
    printVec("Tegangan terurut  ", voltage_mv);

    section("Catatan");
    cout << "  - Kompleksitas waktu: selalu O(n^2) — tidak ada early exit\n";
    cout << "  - Kompleksitas swap : O(n) — minimal dari semua O(n^2) sort\n";
    cout << "  - Tidak stabil: urutan elemen sama bisa berubah\n";
    cout << "  - Use case: memori flash, EEPROM embedded systems\n";

    cout << "\n  Selesai.\n";
    return 0;
}
