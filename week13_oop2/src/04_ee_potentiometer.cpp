// 04_ee_potentiometer.cpp - Potentiometer : Resistor : Component (3-level) + voltage divider
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo04 src/04_ee_potentiometer.cpp
// Run:     ./demo04
#include "oop2.h"

// Level 2: Resistor mewarisi Component
class Resistor : public Component {
protected:
    double resistance;  // Ohm
    double tolerance;   // persen

public:
    Resistor(const string& pn, double r, double tol = 5.0,
             const string& mfr = "Generic")
        : Component(pn, mfr), resistance(r), tolerance(tol) {}

    virtual ~Resistor() override {}

    void setResistance(double r) {
        if (r > 0) resistance = r;
    }
    double getResistance() const { return resistance; }

    void printInfo() const override {
        cout << "  Resistor [" << partNumber << "]: "
             << resistance << " Ohm +/- " << tolerance << "%" << endl;
    }
};

// Level 3: Potentiometer mewarisi Resistor (3-level inheritance)
// Potentiometer IS-A Resistor, Resistor IS-A Component
class Potentiometer : public Resistor {
private:
    double wiperPosition;  // 0.0 (GND end) sampai 1.0 (VCC end)

public:
    Potentiometer(const string& pn, double r, double wiper = 0.5)
        : Resistor(pn, r),        // Resistor memanggil Component secara internal
          wiperPosition(wiper)
    {}

    ~Potentiometer() override {}

    // Validasi posisi wiper 0.0 - 1.0
    void setWiper(double pos) {
        if (pos >= 0.0 && pos <= 1.0) {
            wiperPosition = pos;
        } else {
            cout << "  WARNING: posisi wiper harus 0.0-1.0, diabaikan." << endl;
        }
    }

    double getWiper() const { return wiperPosition; }

    // Resistansi efektif dari terminal GND ke wiper
    double getEffectiveResistance() const {
        return resistance * wiperPosition;  // resistance diwarisi dari Resistor
    }

    // Override printInfo() - panggil Resistor lalu tambah info wiper
    void printInfo() const override {
        Resistor::printInfo();   // cetak info resistor dari parent
        cout << "    Wiper: " << wiperPosition * 100.0 << "% -> "
             << getEffectiveResistance() << " Ohm efektif" << endl;
    }
};

int main() {
    cout << "==========================================\n";
    cout << " Week 13 Demo 04 - EE: Potentiometer    \n";
    cout << "==========================================\n";

    // Potentiometer dasar
    section("1. Potentiometer - 3-level inheritance");
    Potentiometer pot("POT-10k", 10000.0, 0.75);
    pot.printInfo();

    // Metode dari semua level
    cout << "\n  Metode dari semua level inheritance:" << endl;
    cout << "  getPartNumber()  [Component]    = " << pot.getPartNumber() << endl;
    cout << "  getResistance()  [Resistor]     = " << pot.getResistance() << " Ohm" << endl;
    cout << "  getWiper()       [Potentiometer] = "
         << pot.getWiper() * 100 << "%" << endl;
    pot.printPartNumber();    // diwarisi dari Component

    // Atur posisi wiper
    section("2. Mengubah posisi wiper");
    pot.setWiper(0.25);
    pot.printInfo();
    pot.setWiper(1.5);        // nilai tidak valid - ditolak
    pot.printInfo();          // wiper tetap 0.25

    // EE: Potentiometer sebagai voltage divider
    section("3. EE: Voltage Divider menggunakan Potentiometer");
    Potentiometer vd("POT-VD", 10000.0, 0.5);
    double vIn = 5.0;

    cout << "  Potentiometer 10kOhm sebagai pembagi tegangan" << endl;
    cout << "  Vin = " << vIn << " V" << endl;
    cout << endl;

    // Sweep wiper: 0%, 25%, 50%, 75%, 100%
    double positions[] = {0.0, 0.25, 0.5, 0.75, 1.0};
    for (double pos : positions) {
        vd.setWiper(pos);
        double rEff   = vd.getEffectiveResistance();
        double rTotal = vd.getResistance();
        // Vout = Vin * (R_wiper / R_total)
        double vOut   = vIn * (rEff / rTotal);
        cout << "  Wiper " << pos * 100 << "% : R_eff="
             << rEff << " Ohm, Vout=" << vOut << " V" << endl;
    }

    cout << "\n  Selesai.\n";
    return 0;
}
