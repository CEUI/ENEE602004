// oop3.h — abstract base class Component dan helper untuk OOP 3
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Helper: cetak header section dengan garis pemisah
inline void section(const string& t) {
    int fill = max(0, 55 - (int)t.size());
    cout << "\n" << t << " " << string(fill, '-') << endl;
}

// Kelas abstrak — tidak bisa diinstansiasi langsung
// Mendefinisikan kontrak yang WAJIB dipenuhi semua kelas turunan
class Component {
protected:
    string partNumber;  // nomor part (misal: "R1", "C2")
public:
    explicit Component(const string& pn) : partNumber(pn) {}

    virtual void   printInfo() const = 0;  // pure virtual — wajib di-override
    virtual double getValue()  const = 0;  // nilai komponen (Ohm, F, atau H)
    virtual string getUnit()   const = 0;  // satuan: "Ohm", "F", "H"

    // Non-virtual: sama untuk semua turunan
    string getPartNumber() const { return partNumber; }

    // Virtual destructor WAJIB ada di abstract base class
    // Tanpa ini: memory leak saat delete lewat pointer base
    virtual ~Component() = default;
};
