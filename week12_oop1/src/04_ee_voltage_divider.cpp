// 04_ee_voltage_divider.cpp - EE: Resistor terenkapsulasi + voltage divider + paralel
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo04 src/04_ee_voltage_divider.cpp
// Run:     ./demo04
#include "oop1.h"

// Class Resistor - terenkapsulasi (pola dari demo 02)
class Resistor {
private:
    string partNumber;
    double resistance;   // Ohm - selalu > 0
    double tolerance;    // persen

public:
    Resistor(const string& pn, double r, double tol = 5.0)
        : partNumber(pn), resistance(0.0), tolerance(tol)
    {
        setResistance(r);
    }

    void setResistance(double r) {
        if (r > 0) {
            resistance = r;
        } else {
            cout << "  WARNING: resistance tidak valid untuk "
                 << partNumber << endl;
        }
    }

    double getResistance() const { return resistance; }
    double getTolerance()  const { return tolerance;  }
    string getPartNumber() const { return partNumber; }

    void printInfo() const {
        cout << "  [" << partNumber << "] "
             << resistance << " Ohm +/- " << tolerance << "%" << endl;
    }
};

// Fungsi bebas: hitung resistansi paralel dua resistor
double parallelR(double r1, double r2) {
    if (r1 + r2 == 0.0) return 0.0;
    return (r1 * r2) / (r1 + r2);
}

int main() {
    cout << "==========================================\n";
    cout << " Week 12 Demo 04 - EE: Voltage Divider   \n";
    cout << "==========================================\n";

    // Voltage divider: dua resistor seri
    section("1. Voltage Divider (pembagi tegangan)");
    Resistor rTop("R_TOP", 10000.0, 1.0);   // 10 kOhm atas
    Resistor rBot("R_BOT",  4700.0, 1.0);   // 4.7 kOhm bawah

    double vIn  = 5.0;
    double rT   = rTop.getResistance();
    double rB   = rBot.getResistance();
    // Vout = Vin * R_bot / (R_top + R_bot)
    double vOut = vIn * (rB / (rT + rB));

    cout << "  Rangkaian: Vin -- R_TOP -- Vout -- R_BOT -- GND" << endl;
    cout << endl;
    rTop.printInfo();
    rBot.printInfo();
    cout << endl;
    cout << "  Vin  = " << vIn  << " V" << endl;
    cout << "  Vout = Vin x R_bot / (R_top + R_bot)" << endl;
    cout << "       = " << vIn << " x " << rB << " / (" << rT
         << " + " << rB << ")" << endl;
    cout << "       = " << vOut << " V" << endl;

    // Resistor paralel
    section("2. Resistansi Paralel");
    Resistor rA("R_A", 1000.0);
    Resistor rBx("R_B", 1000.0);
    Resistor rC("R_C", 2200.0);

    double rAB = parallelR(rA.getResistance(), rBx.getResistance());
    double rAC = parallelR(rA.getResistance(), rC.getResistance());

    rA.printInfo();
    rBx.printInfo();
    rC.printInfo();
    cout << endl;
    cout << "  R_A || R_B = " << rAB << " Ohm  (2x1k paralel = 500 Ohm)" << endl;
    cout << "  R_A || R_C = " << rAC << " Ohm" << endl;

    // Voltage divider dengan beban paralel
    section("3. Voltage Divider dengan Beban Paralel");
    Resistor rLoad("R_LOAD", 10000.0);
    double rBotLoad = parallelR(rBot.getResistance(), rLoad.getResistance());
    double vOutLoad = vIn * (rBotLoad / (rTop.getResistance() + rBotLoad));

    cout << "  Beban (R_LOAD) dihubungkan paralel dengan R_BOT" << endl;
    rLoad.printInfo();
    cout << "  R_BOT || R_LOAD = " << rBotLoad << " Ohm" << endl;
    cout << "  Vout dengan beban = " << vOutLoad << " V" << endl;
    cout << "  (tanpa beban: " << vOut << " V - efek loading)" << endl;

    cout << "\n  Selesai.\n";
    return 0;
}
