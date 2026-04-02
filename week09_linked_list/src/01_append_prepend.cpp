// ============================================================
// 01_append_prepend.cpp — Demo: Membangun List (append & prepend)
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Kompilasi:
//   g++ -std=c++17 -Wall -o demo01 sll_ops.cpp 01_append_prepend.cpp
// Jalankan:
//   ./demo01
// ============================================================
#include "sll_ops.h"

int main() {
    cout << "============================================" << endl;
    cout << " Demo 01: append() dan prepend()           " << endl;
    cout << "============================================" << endl;

    Node* head = nullptr;  // list dimulai kosong

    // ── append: tambah node di akhir list ────────────────────
    // Setiap panggilan append menelusuri list sampai ujung (O(n))
    section("append(10), append(20), append(30)");
    append(head, 10);
    append(head, 20);
    append(head, 30);
    printList(head);
    // Output: 10 -> 20 -> 30 -> NULL

    // ── append lagi ───────────────────────────────────────────
    section("append(40), append(50)");
    append(head, 40);
    append(head, 50);
    printList(head);
    // Output: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    // ── prepend: tambah node di awal list ────────────────────
    // Hanya 2 operasi pointer — O(1), sangat efisien!
    section("prepend(5) — sisipkan 5 di awal");
    prepend(head, 5);
    printList(head);
    // Output: 5 -> 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    section("prepend(1) — sisipkan 1 di awal lagi");
    prepend(head, 1);
    printList(head);
    // Output: 1 -> 5 -> 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    // ── Bersihkan memori ─────────────────────────────────────
    freeList(head);
    cout << "\n  Memori dibebaskan. Selesai." << endl;
    return 0;
}
