// 01_bubble_sort.cpp — demo bubble sort dengan trace
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo01 src/sort_ops.cpp src/01_bubble_sort.cpp
// Run:     ./demo01
#include "sort_ops.h"

int main() {
    cout << "==========================================\n";
    cout << " Demo 01: Bubble Sort — O(n^2) / O(n)   \n";
    cout << "==========================================\n";

    section("Trace Langkah Demi Langkah pada {5,3,1,4,2}");
    bubbleSortTrace({5, 3, 1, 4, 2});

    section("Bubble Sort pada Data Sensor");
    vector<int> data = {64, 25, 12, 22, 11, 45, 33, 8, 90, 17};
    printVec("Sebelum", data);
    bubbleSort(data);
    printVec("Sesudah", data);

    section("Demonstrasi Early Exit (data hampir terurut)");
    // Bubble sort berhenti lebih awal jika tidak ada pertukaran di satu pass
    vector<int> nearSorted = {1, 2, 3, 5, 4};
    printVec("Input  ", nearSorted);
    bubbleSortTrace(nearSorted);

    section("Catatan");
    cout << "  - Kompleksitas waktu: O(n^2) rata-rata dan terburuk\n";
    cout << "  - Kompleksitas waktu: O(n) terbaik (data sudah terurut)\n";
    cout << "  - Kompleksitas ruang: O(1) — in-place sorting\n";
    cout << "  - Optimasi: early exit jika tidak ada swap dalam satu pass\n";

    cout << "\n  Selesai.\n";
    return 0;
}
