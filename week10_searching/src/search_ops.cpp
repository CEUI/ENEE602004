// search_ops.cpp — implementasi fungsi pencarian
// ENEE602004 Algoritma Pemrograman dan Praktikum
#include "search_ops.h"

// ── Linear Search ────────────────────────────────────────────────
// Memeriksa setiap elemen dari kiri ke kanan
// Kompleksitas: O(n) — tidak memerlukan data terurut
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target)
            return i;   // elemen ditemukan pada index i
    }
    return -1;          // elemen tidak ditemukan
}

// ── Binary Search ────────────────────────────────────────────────
// Divide-and-conquer: bandingkan dengan tengah, eliminasi setengah
// Kompleksitas: O(log n) — MEMERLUKAN data terurut
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = (int)arr.size() - 1;

    while (low <= high) {
        // Hindari integer overflow dengan rumus ini
        int mid = low + (high - low) / 2;

        if      (arr[mid] == target) return mid;      // ditemukan!
        else if (arr[mid]  < target) low  = mid + 1;  // cari di kanan
        else                         high = mid - 1;  // cari di kiri
    }
    return -1; // tidak ditemukan
}

// ── Binary Search Trace ──────────────────────────────────────────
// Menampilkan setiap langkah pencarian untuk keperluan edukasi
void binarySearchTrace(const vector<int>& arr, int target) {
    cout << "  Mencari " << target
         << " dalam array terurut ukuran " << arr.size() << ":\n";
    int low = 0, high = (int)arr.size() - 1, step = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "    Langkah " << step++ << ": low=" << low
             << " high=" << high << " mid=" << mid
             << " arr[mid]=" << arr[mid];
        if      (arr[mid] == target) { cout << "  -> DITEMUKAN!\n"; return; }
        else if (arr[mid]  < target) { cout << "  -> ke kanan\n"; low  = mid + 1; }
        else                         { cout << "  -> ke kiri\n";  high = mid - 1; }
    }
    cout << "    -> TIDAK DITEMUKAN\n";
}
