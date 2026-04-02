// search.h — header umum untuk algoritma pencarian
// ENEE602004 Algoritma Pemrograman dan Praktikum
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

inline void section(const string& t) {
    int fill = max(0, 55 - (int)t.size());
    cout << "\n" << t << " " << string(fill, '-') << endl;
}
