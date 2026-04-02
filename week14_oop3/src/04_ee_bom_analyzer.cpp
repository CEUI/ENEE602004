// 04_ee_bom_analyzer.cpp — aplikasi EE: Bill of Materials analyzer
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo04 src/04_ee_bom_analyzer.cpp
// Run:     ./demo04
#include "oop3.h"
#include <iomanip>

// ── Kelas komponen dengan format output yang lebih lengkap ────
class Resistor : public Component {
    double resistance;  // dalam Ohm
public:
    Resistor(const string& pn, double r) : Component(pn), resistance(r) {}
    void printInfo() const override {
        cout << "  R  " << left << setw(8) << partNumber
             << " | " << setw(10) << resistance << " Ohm" << endl;
    }
    double getValue() const override { return resistance; }
    string getUnit()  const override { return "Ohm"; }
};

class Capacitor : public Component {
    double capacitance; // dalam Farad
public:
    Capacitor(const string& pn, double c) : Component(pn), capacitance(c) {}
    void printInfo() const override {
        cout << "  C  " << left << setw(8) << partNumber
             << " | " << setw(10) << capacitance * 1e9 << " nF" << endl;
    }
    double getValue() const override { return capacitance; }
    string getUnit()  const override { return "F"; }
};

class Inductor : public Component {
    double inductance;  // dalam Henry
public:
    Inductor(const string& pn, double l) : Component(pn), inductance(l) {}
    void printInfo() const override {
        cout << "  L  " << left << setw(8) << partNumber
             << " | " << setw(10) << inductance * 1e6 << " uH" << endl;
    }
    double getValue() const override { return inductance; }
    string getUnit()  const override { return "H"; }
};

int main() {
    cout << "=== Demo 04: EE BOM Analyzer ===" << endl;

    // ── BOM: campuran berbagai komponen via unique_ptr ─────────
    section("Bill of Materials -- PCB Power Filter");
    vector<unique_ptr<Component>> bom;
    bom.push_back(make_unique<Resistor> ("R1",   100.0));
    bom.push_back(make_unique<Resistor> ("R2",  4700.0));
    bom.push_back(make_unique<Resistor> ("R3",   220.0));
    bom.push_back(make_unique<Capacitor>("C1",  100e-9));
    bom.push_back(make_unique<Capacitor>("C2",   10e-6));
    bom.push_back(make_unique<Inductor> ("L1",  100e-6));
    bom.push_back(make_unique<Inductor> ("L2",   47e-6));

    cout << "\n  Type Part     | Value" << endl;
    cout << "  " << string(32, '-') << endl;
    for (const auto& c : bom)
        c->printInfo();  // polimorfisme: setiap tipe tahu cara tampilkan dirinya

    // ── Hitung ringkasan per tipe secara polimorfik ───────────
    section("Ringkasan BOM");
    double sumR=0, sumC=0, sumL=0;
    int    cntR=0, cntC=0, cntL=0;
    for (const auto& c : bom) {
        if      (c->getUnit()=="Ohm") { sumR += c->getValue(); cntR++; }
        else if (c->getUnit()=="F")   { sumC += c->getValue(); cntC++; }
        else if (c->getUnit()=="H")   { sumL += c->getValue(); cntL++; }
    }
    cout << "  Resistor  : " << cntR << " parts, total " << sumR     << " Ohm"<< endl;
    cout << "  Capacitor : " << cntC << " parts, total " << sumC*1e9 << " nF" << endl;
    cout << "  Inductor  : " << cntL << " parts, total " << sumL*1e6 << " uH" << endl;
    cout << "  Total komponen: " << bom.size() << " parts" << endl;
    return 0;
}
