// oop1.h - header umum untuk OOP 1
// ENEE602004 Algoritma Pemrograman dan Praktikum
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

inline void section(const string& t) {
    int fill = max(0, 55 - (int)t.size());
    cout << "\n" << t << " " << string(fill, '-') << endl;
}
