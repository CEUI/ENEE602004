// sort.h — header umum untuk algoritma sorting
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

inline void printVec(const string& label, const vector<int>& v) {
    cout << "  " << label << ": [ ";
    for (int x : v) cout << x << " ";
    cout << "]" << endl;
}
