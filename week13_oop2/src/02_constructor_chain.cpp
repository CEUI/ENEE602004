// 02_constructor_chain.cpp - Urutan constructor dan destructor saat inheritance
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo02 src/02_constructor_chain.cpp
// Run:     ./demo02
#include "oop2.h"

// Demo sederhana: Base - Child (cetak pesan ctor/dtor)
class Base {
public:
    Base()          { cout << "  [Base ctor]" << endl; }
    virtual ~Base() { cout << "  [Base dtor]" << endl; }
};

class Child : public Base {
public:
    Child()  : Base() { cout << "  [Child ctor]" << endl; }
    ~Child() override { cout << "  [Child dtor]" << endl; }
};

// Demo EE: Component (dengan pesan) - ResistorV
class CompV : public Component {
public:
    CompV(const string& pn) : Component(pn) {
        cout << "  [CompV ctor] " << pn << endl;
    }
    ~CompV() override {
        cout << "  [CompV dtor] " << partNumber << endl;
    }
};

class ResistorV : public CompV {
protected:
    double resistance;

public:
    ResistorV(const string& pn, double r)
        : CompV(pn), resistance(r)   // constructor chain: CompV -> Component
    {
        cout << "  [ResistorV ctor] R=" << r << " Ohm" << endl;
    }
    ~ResistorV() override {
        cout << "  [ResistorV dtor] " << partNumber << endl;
    }
    void printInfo() const override {
        cout << "  Resistor [" << partNumber << "]: "
             << resistance << " Ohm" << endl;
    }
};

int main() {
    cout << "==========================================\n";
    cout << " Week 13 Demo 02 - Constructor Chain     \n";
    cout << "==========================================\n";

    // Demo sederhana: urutan ctor/dtor
    section("1. Urutan ctor/dtor - Base dan Child");
    cout << "  Membuat object Child..." << endl;
    {
        Child obj;
        cout << "  Object ada. Keluar scope..." << endl;
    }  // destructor berjalan di sini, urutan TERBALIK
    cout << "  (scope selesai)" << endl;

    // Demo EE: ResistorV -> CompV -> Component
    section("2. Urutan ctor/dtor - Component dan Resistor (EE)");
    cout << "  Membuat object ResistorV..." << endl;
    {
        ResistorV r("R-1k", 1000.0);
        cout << "  Object ada. Keluar scope..." << endl;
        r.printInfo();
    }  // ~ResistorV -> ~CompV -> ~Component
    cout << "  (scope selesai)" << endl;

    // Aturan urutan
    section("3. Aturan urutan constructor dan destructor");
    cout << "  Constructor: dari class PALING ATAS ke bawah" << endl;
    cout << "    Component ctor -> CompV ctor -> ResistorV ctor" << endl;
    cout << "  Destructor : dari class PALING BAWAH ke atas (terbalik)" << endl;
    cout << "    ~ResistorV -> ~CompV -> ~Component" << endl;

    cout << "\n  Selesai.\n";
    return 0;
}
