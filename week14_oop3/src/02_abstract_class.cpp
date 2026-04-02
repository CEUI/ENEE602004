// 02_abstract_class.cpp — pure virtual function dan abstract class
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo02 src/02_abstract_class.cpp
// Run:     ./demo02
#include "oop3.h"

// ── Kelas konkret: WAJIB implementasi semua pure virtual ──────
class Resistor : public Component {
    double resistance;
public:
    Resistor(const string& pn, double r) : Component(pn), resistance(r) {}
    void   printInfo() const override {
        cout << "  Resistor   [" << partNumber << "] : "
             << resistance << " Ohm" << endl;
    }
    double getValue() const override { return resistance; }
    string getUnit()  const override { return "Ohm"; }
};

class Capacitor : public Component {
    double capacitance;
public:
    Capacitor(const string& pn, double c) : Component(pn), capacitance(c) {}
    void   printInfo() const override {
        cout << "  Capacitor  [" << partNumber << "] : "
             << capacitance * 1e6 << " uF" << endl;
    }
    double getValue() const override { return capacitance; }
    string getUnit()  const override { return "F"; }
};

class Inductor : public Component {
    double inductance;
public:
    Inductor(const string& pn, double l) : Component(pn), inductance(l) {}
    void   printInfo() const override {
        cout << "  Inductor   [" << partNumber << "] : "
             << inductance * 1e3 << " mH" << endl;
    }
    double getValue() const override { return inductance; }
    string getUnit()  const override { return "H"; }
};

int main() {
    cout << "=== Demo 02: Abstract Class ===" << endl;

    // Component c("X");  // COMPILE ERROR: Component bersifat abstract!
    // Kelas abstrak tidak bisa diinstansiasi langsung.
    section("1. Tidak bisa instantiasi Component langsung");
    cout << "  // Component c(\"X\"); -> error: abstract class" << endl;
    cout << "  Harus gunakan kelas konkret (Resistor, Capacitor, dll.)" << endl;

    // ── Polimorfisme lewat array pointer base ─────────────────
    section("2. Satu loop, banyak tipe -- polymorphism");
    Component* circuit[3];
    circuit[0] = new Resistor ("R1", 470.0);
    circuit[1] = new Capacitor("C1", 100e-6);
    circuit[2] = new Inductor ("L1",  10e-3);

    cout << "\n  Bill of Materials:" << endl;
    for (int i = 0; i < 3; i++)
        circuit[i]->printInfo();   // runtime dispatch via vtable

    // Cleanup — virtual destructor memastikan destruktor turunan dipanggil
    for (int i = 0; i < 3; i++) delete circuit[i];

    cout << "\nKesimpulan: abstract class memaksa kelas turunan" << endl;
    cout << "            mengimplementasi kontrak (pure virtual)." << endl;
    return 0;
}
