// sort_ops.h — deklarasi fungsi sorting
// ENEE602004 Algoritma Pemrograman dan Praktikum
#pragma once
#include "sort.h"

// Bubble sort — tukar pasangan yang tidak terurut secara berulang
// Kompleksitas: O(n^2) rata-rata, O(n) terbaik (dengan early exit)
void bubbleSort(vector<int>& arr);

// Insertion sort — sisipkan elemen ke posisi yang tepat pada partisi terurut
// Kompleksitas: O(n^2) rata-rata, O(n) terbaik (data hampir terurut)
void insertionSort(vector<int>& arr);

// Selection sort — temukan minimum, tukar ke depan
// Kompleksitas: selalu O(n^2), tetapi hanya O(n) swap
void selectionSort(vector<int>& arr);

// Bubble sort dengan output langkah demi langkah (pass-by-value)
void bubbleSortTrace(vector<int> arr);
