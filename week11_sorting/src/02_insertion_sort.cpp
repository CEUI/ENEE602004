// 02_insertion_sort.cpp — demo insertion sort, kasus terbaik hampir terurut
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo02 src/sort_ops.cpp src/02_insertion_sort.cpp
// Run:     ./demo02
#include "sort_ops.h"

int main() {
    cout << "==========================================\n";
    cout << " Demo 02: Insertion Sort                 \n";
    cout << "==========================================\n";

    section("Insertion Sort pada Data Acak");
    vector<int> data = {64, 25, 12, 22, 11, 45, 33, 8, 90, 17};
    printVec("Sebelum", data);
    insertionSort(data);
    printVec("Sesudah", data);

    section("Kasus Terbaik: Data Hampir Terurut — O(n)");
    // Insertion sort sangat efisien pada data hampir terurut
    // karena inner while loop jarang berjalan
    vector<int> nearlySorted = {1, 2, 4, 3, 5, 6, 7, 8, 9, 10};
    printVec("Input         ", nearlySorted);
    insertionSort(nearlySorted);
    printVec("Setelah insert", nearlySorted);
    cout << "  (ideal untuk data yang hampir terurut)\n";

    section("Kasus Terburuk: Data Terbalik — O(n^2)");
    vector<int> reversed = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printVec("Input  ", reversed);
    insertionSort(reversed);
    printVec("Sorted ", reversed);
    cout << "  (setiap elemen harus digeser penuh ke kiri)\n";

    section("Catatan");
    cout << "  - Kasus terbaik : O(n) — data sudah/hampir terurut\n";
    cout << "  - Kasus rata-rata: O(n^2)\n";
    cout << "  - Kasus terburuk: O(n^2) — data terbalik\n";
    cout << "  - Stabil: urutan elemen sama tetap terjaga\n";
    cout << "  - Berguna: data stream real-time, array kecil\n";

    cout << "\n  Selesai.\n";
    return 0;
}
