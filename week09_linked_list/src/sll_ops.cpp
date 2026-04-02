// ============================================================
// sll_ops.cpp — Implementasi operasi Singly Linked List
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Kompilasi bersama file demo:
//   g++ -std=c++17 -Wall -o <output> sll_ops.cpp <demo>.cpp
// ============================================================
#include "sll_ops.h"

// ── search — O(n) ────────────────────────────────────────────
// Telusuri dari head sampai nilai ditemukan atau list habis.
Node* search(Node* head, int target) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == target)
            return curr;       // ditemukan, kembalikan pointer-nya
        curr = curr->next;     // maju ke node berikutnya
    }
    return nullptr;            // tidak ditemukan
}

// ── prepend — O(1) ───────────────────────────────────────────
// Hanya 2 operasi pointer, tidak perlu menelusuri list.
void prepend(Node*& head, int val) {
    Node* n = new Node(val);   // alokasi node baru di heap
    n->next  = head;           // node baru → head lama
    head     = n;              // head sekarang = node baru
}

// ── append — O(n) ────────────────────────────────────────────
// Harus jalan ke node terakhir terlebih dahulu.
void append(Node*& head, int val) {
    Node* n = new Node(val);
    if (head == nullptr) {     // list kosong: node baru langsung jadi head
        head = n;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;     // jalan ke node terakhir
    curr->next = n;            // sambungkan
}

// ── insertAfter — O(1) setelah prev diketahui ────────────────
// URUTAN PENTING: sambungkan n->next SEBELUM memutus prev->next!
void insertAfter(Node* prev, int val) {
    if (prev == nullptr) return;
    Node* n    = new Node(val);
    n->next    = prev->next;   // langkah 1: sambungkan ke depan dulu
    prev->next = n;            // langkah 2: sambungkan ke belakang
}

// ── deleteNode — O(n) ────────────────────────────────────────
// Tiga kasus: hapus node tengah, node head, atau tidak ditemukan.
bool deleteNode(Node*& head, int val) {
    Node* prev = nullptr;
    Node* curr = head;

    // Jalan sambil melacak node sebelumnya
    while (curr != nullptr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) return false;  // tidak ditemukan

    if (prev == nullptr)                // menghapus node head
        head = curr->next;
    else
        prev->next = curr->next;        // lewati node yang dihapus

    delete curr;                        // WAJIB: bebaskan memori heap
    return true;
}

// ── printList — O(n) ─────────────────────────────────────────
void printList(Node* head) {
    if (head == nullptr) {
        cout << "[empty list]" << endl;
        return;
    }
    for (Node* c = head; c != nullptr; c = c->next) {
        cout << c->data;
        if (c->next) cout << " -> ";
    }
    cout << " -> NULL" << endl;
}

// ── freeList — O(n) ──────────────────────────────────────────
// Simpan pointer berikutnya sebelum delete, lalu bebaskan satu per satu.
void freeList(Node*& head) {
    while (head != nullptr) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}
