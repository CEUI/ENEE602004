// sort_ops.cpp — implementasi fungsi sorting
// ENEE602004 Algoritma Pemrograman dan Praktikum
#include "sort_ops.h"

// ── Bubble Sort ──────────────────────────────────────────────────
// Tukar pasangan elemen bersebelahan yang tidak terurut secara berulang
// Elemen terbesar "menggelembung" ke akhir array di setiap pass
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // optimasi: tandai apakah ada pertukaran
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;   // array sudah terurut, hentikan lebih awal
    }
}

// ── Insertion Sort ───────────────────────────────────────────────
// Kembangkan partisi terurut dari kiri satu per satu
// Ambil elemen berikutnya (key), geser yang lebih besar ke kanan
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // elemen yang akan disisipkan
        int j   = i - 1;
        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;   // tempatkan key di posisi yang tepat
    }
}

// ── Selection Sort ───────────────────────────────────────────────
// Temukan elemen minimum di partisi tidak terurut, tukar ke depan
// Jumlah swap selalu O(n) — cocok untuk memori flash (write mahal)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;  // asumsi minimum ada di posisi i
        // Cari minimum di sisa array
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;         // update posisi minimum
        if (min_idx != i)
            swap(arr[i], arr[min_idx]); // tempatkan minimum di depan
    }
}

// ── Bubble Sort Trace ────────────────────────────────────────────
// Tampilkan setiap pass untuk keperluan edukasi (pass-by-value)
void bubbleSortTrace(vector<int> arr) {
    int n = arr.size();
    cout << "  Awal    : ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        cout << "  Pass " << i + 1 << "  : ";
        for (int x : arr) cout << x << " ";
        cout << "\n";
        if (!swapped) { cout << "  (early exit — sudah terurut)\n"; break; }
    }
}
