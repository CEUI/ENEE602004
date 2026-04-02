// ============================================================
// 03_insert_delete.cpp — Demo: insertAfter dan deleteNode
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Kompilasi:
//   g++ -std=c++17 -Wall -o demo03 sll_ops.cpp 03_insert_delete.cpp
// Jalankan:
//   ./demo03
// ============================================================
#include "sll_ops.h"

int main() {
    cout << "============================================" << endl;
    cout << " Demo 03: insertAfter() dan deleteNode()   " << endl;
    cout << "============================================" << endl;

    Node* head = nullptr;
    for (int v : {10, 20, 30, 40, 50})
        append(head, v);

    section("List awal");
    printList(head);

    // ── insertAfter ───────────────────────────────────────────
    // URUTAN PENTING:
    //   (1) n->next = prev->next   ← sambung ke depan DULU
    //   (2) prev->next = n         ← baru sambung ke belakang
    section("insertAfter(node(20), 25) — sisipkan 25 setelah 20");
    insertAfter(search(head, 20), 25);
    printList(head);   // 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> NULL

    section("insertAfter(node(50), 60) — sisipkan di akhir");
    insertAfter(search(head, 50), 60);
    printList(head);   // 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> 60 -> NULL

    // ── deleteNode: 3 kasus ───────────────────────────────────

    // Kasus 1: Hapus node tengah
    section("deleteNode(25) — hapus node tengah");
    deleteNode(head, 25);
    printList(head);   // 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    // Kasus 2: Hapus node kepala (head)
    // prev == nullptr, sehingga head harus digeser
    section("deleteNode(10) — hapus node kepala (head)");
    deleteNode(head, 10);
    printList(head);   // 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    // Kasus 3: Hapus node ekor (tail)
    // curr->next == nullptr setelah penghapusan
    section("deleteNode(60) — hapus node ekor (tail)");
    deleteNode(head, 60);
    printList(head);   // 20 -> 30 -> 40 -> 50 -> NULL

    // Kasus 4: Nilai tidak ditemukan
    section("deleteNode(99) — nilai tidak ada dalam list");
    bool ok = deleteNode(head, 99);
    cout << "  Hasil: " << (ok ? "dihapus" : "tidak ditemukan") << endl;
    printList(head);   // list tidak berubah

    freeList(head);
    cout << "\n  Memori dibebaskan. Selesai." << endl;
    return 0;
}
