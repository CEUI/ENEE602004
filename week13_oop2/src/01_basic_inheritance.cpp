// 01_basic_inheritance.cpp - Resistor dan Capacitor mewarisi Component
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo01 src/01_basic_inheritance.cpp
// Run:     ./demo01
#include "oop2.h"

// Derived class Resistor - mewarisi Component (IS-A Component)
class Resistor : public Component {
protected:
    double resistance;  // Ohm
    double tolerance;   // persen

public:
    // Constructor memanggil constructor Component di initializer list
    Resistor(const string& pn, double r, double tol = 5.0,
             const string& mfr = "Generic")
        : Component(pn, mfr),         // panggil constructor parent terlebih dahulu
          resistance(r), tolerance(tol)
    {}

    double getResistance() const { return resistance; }

    // override: ganti implementasi printInfo() dari Component
    void printInfo() const override {
        cout << "  Resistor [" << partNumber << "]: "
             << resistance << " Ohm +/- " << tolerance << "%" << endl;
    }
};

// Derived class Capacitor - mewarisi Component (IS-A Component)
class Capacitor : public Component {
private:
    double capacitance;    // Farad
    double voltageRating;  // Volt

public:
    Capacitor(const string& pn, double c, double vRating = 50.0)
        : Component(pn), capacitance(c), voltageRating(vRating)
    {}

    void printInfo() const override {
        cout << "  Capacitor [" << partNumber << "]: "
             << capacitance * 1e6 << " uF, "
             << voltageRating << " V rated" << endl;
    }
};

int main() {
    cout << "==========================================\n";
    cout << " Week 13 Demo 01 - Basic Inheritance     \n";
    cout << "==========================================\n";

    section("1. Resistor mewarisi Component");
    Resistor r1("R-470",  470.0, 1.0, "Vishay");
    Resistor r2("R-10k", 10000.0);

    // printPartNumber() diwarisi dari Component - tidak perlu didefinisikan ulang
    cout << "  printPartNumber() - diwarisi dari Component:" << endl;
    r1.printPartNumber();
    r2.printPartNumber();

    // printInfo() - versi Resistor (override)
    cout << "\n  printInfo() - override di Resistor:" << endl;
    r1.printInfo();
    r2.printInfo();

    section("2. Capacitor mewarisi Component");
    Capacitor c1("C-100nF", 100e-9, 16.0);
    Capacitor c2("C-47uF",   47e-6);

    cout << "  printPartNumber() - diwarisi dari Component:" << endl;
    c1.printPartNumber();
    c2.printPartNumber();

    cout << "\n  printInfo() - override di Capacitor:" << endl;
    c1.printInfo();
    c2.printInfo();

    section("3. getPartNumber() - diwarisi, tidak dioverride");
    cout << "  r1.getPartNumber() = " << r1.getPartNumber() << endl;
    cout << "  c1.getPartNumber() = " << c1.getPartNumber() << endl;

    cout << "\n  Selesai.\n";
    return 0;
}
