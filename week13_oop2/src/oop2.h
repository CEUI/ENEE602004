// oop2.h - header umum + base class Component untuk OOP 2
// ENEE602004 Algoritma Pemrograman dan Praktikum
#pragma once
#include <iostream>
#include <string>
using namespace std;

inline void section(const string& t) {
    int fill = max(0, 55 - (int)t.size());
    cout << "\n" << t << " " << string(fill, '-') << endl;
}

// Base class Component - digunakan di semua demo
class Component {
protected:
    string partNumber;
    string manufacturer;
public:
    Component(const string& pn, const string& mfr = "Generic")
        : partNumber(pn), manufacturer(mfr) {}
    virtual ~Component() {}
    void printPartNumber() const {
        cout << "  Part: " << partNumber << "  Mfr: " << manufacturer << endl;
    }
    virtual void printInfo() const {
        cout << "  Komponen generik: " << partNumber << endl;
    }
    string getPartNumber() const { return partNumber; }
};
