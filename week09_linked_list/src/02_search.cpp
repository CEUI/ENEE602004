// ============================================================
// 02_search.cpp — Demo: Pencarian (search)
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Kompilasi:
//   g++ -std=c++17 -Wall -o demo02 sll_ops.cpp 02_search.cpp
// Jalankan:
//   ./demo02
// ============================================================
#include "sll_ops.h"

int main() {
    cout << "============================================" << endl;
    cout << " Demo 02: search()                         " << endl;
    cout << "============================================" << endl;

    // Bangun list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = nullptr;
    for (int v : {10, 20, 30, 40, 50})
        append(head, v);

    section("List awal");
    printList(head);

    // ── search: ditemukan ─────────────────────────────────────
    // Fungsi mengembalikan pointer ke node, bukan hanya true/false.
    // Pointer ini bisa langsung digunakan untuk operasi selanjutnya.
    section("search(30) — mencari nilai 30");
    Node* found = search(head, 30);
    if (found)
        cout << "  Ditemukan! Nilai: " << found->data
             << "  (next menunjuk ke: "
             << (found->next ? to_string(found->next->data) : "NULL")
             << ")" << endl;
    else
        cout << "  Tidak ditemukan." << endl;

    // ── search: tidak ditemukan ───────────────────────────────
    section("search(99) — mencari nilai yang tidak ada");
    found = search(head, 99);
    if (found)
        cout << "  Ditemukan: " << found->data << endl;
    else
        cout << "  Tidak ditemukan. Fungsi mengembalikan nullptr." << endl;

    // ── Gunakan hasil search sebagai input insertAfter ───────
    // Ini pola umum: cari dulu, lalu gunakan pointer-nya
    section("search(20) lalu insertAfter — sisipkan 25 setelah 20");
    Node* node20 = search(head, 20);
    if (node20) {
        insertAfter(node20, 25);
        printList(head);   // 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> NULL
    }

    freeList(head);
    cout << "\n  Memori dibebaskan. Selesai." << endl;
    return 0;
}
