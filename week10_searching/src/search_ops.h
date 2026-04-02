// search_ops.h — deklarasi fungsi pencarian
// ENEE602004 Algoritma Pemrograman dan Praktikum
#pragma once
#include "search.h"

// Linear search — memeriksa setiap elemen satu per satu
// Mengembalikan index jika ditemukan, -1 jika tidak
int linearSearch(const vector<int>& arr, int target);

// Binary search — divide-and-conquer, memerlukan data terurut
// Mengembalikan index jika ditemukan, -1 jika tidak
int binarySearch(const vector<int>& arr, int target);

// Binary search dengan output langkah demi langkah
// Berguna untuk memahami proses pencarian
void binarySearchTrace(const vector<int>& arr, int target);
