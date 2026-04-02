// 03_unique_ptr.cpp — polimorfisme modern dengan std::unique_ptr
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo03 src/03_unique_ptr.cpp
// Run:     ./demo03
#include "oop3.h"

// ── Kelas konkret (sama seperti demo02) ───────────────────────
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
    cout << "=== Demo 03: unique_ptr + Polymorphism ===" << endl;

    // ── vector<unique_ptr<Component>> — tidak perlu delete manual ──
    section("1. unique_ptr: otomatis hapus saat keluar scope");
    vector<unique_ptr<Component>> board;
    board.push_back(make_unique<Resistor> ("R1",  330.0));
    board.push_back(make_unique<Capacitor>("C1",   47e-6));
    board.push_back(make_unique<Inductor> ("L1",    1e-3));
    board.push_back(make_unique<Resistor> ("R2", 4700.0));

    cout << "\n  Semua komponen (range-for + unique_ptr):" << endl;
    for (const auto& comp : board)
        comp->printInfo();   // polimorfisme — setiap tipe panggil printInfo-nya

    // ── Filter dan hitung total per tipe ──────────────────────
    section("2. Filter by getUnit() -- hitung total per tipe");
    double totalR = 0.0; int cntR = 0;
    double totalC = 0.0; int cntC = 0;
    for (const auto& comp : board) {
        if (comp->getUnit() == "Ohm") { totalR += comp->getValue(); cntR++; }
        if (comp->getUnit() == "F")   { totalC += comp->getValue(); cntC++; }
    }
    cout << "  Resistor  : " << cntR << " parts, total " << totalR << " Ohm" << endl;
    cout << "  Capacitor : " << cntC << " parts, total " << totalC * 1e6 << " uF" << endl;

    // board keluar scope -> semua unique_ptr otomatis hapus objek heap
    cout << "\nKeluar scope -> semua unique_ptr otomatis di-delete." << endl;
    return 0;
}
