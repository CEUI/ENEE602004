// ============================================================
// sll_ops.h — Deklarasi fungsi-fungsi operasi Singly Linked List
// ENEE602004 Algoritma Pemrograman dan Praktikum
// ============================================================
#pragma once
#include "node.h"

// Cari node dengan nilai target — O(n)
Node* search(Node* head, int target);

// Sisipkan node baru di awal list — O(1)
void prepend(Node*& head, int val);

// Sisipkan node baru di akhir list — O(n)
void append(Node*& head, int val);

// Sisipkan node baru tepat setelah node 'prev' — O(1)
void insertAfter(Node* prev, int val);

// Hapus node dengan nilai val — O(n)
// Mengembalikan true jika berhasil, false jika tidak ditemukan
bool deleteNode(Node*& head, int val);

// Cetak semua node dari head ke NULL — O(n)
void printList(Node* head);

// Bebaskan semua memori heap — WAJIB dipanggil di akhir program!
void freeList(Node*& head);
