// 02_encapsulation.cpp - Resistor: private data, constructor, setter, getter
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo02 src/02_encapsulation.cpp
// Run:     ./demo02
#include "oop1.h"

// Class Resistor - terenkapsulasi
// Data private: hanya bisa diakses melalui method public
class Resistor {
private:
    string partNumber;   // nomor part - hanya bisa dibaca via getter
    double resistance;   // Ohm - selalu > 0, dijaga oleh setter
    double tolerance;    // persen - 0..100

public:
    // Constructor: member-initializer list lebih efisien dari assignment
    Resistor(const string& pn, double r, double tol = 5.0)
        : partNumber(pn), resistance(0.0), tolerance(tol)
    {
        setResistance(r);  // gunakan setter agar validasi langsung berlaku
    }

    // Setter dengan validasi: tolak nilai tidak valid
    void setResistance(double r) {
        if (r > 0) {
            resistance = r;
        } else {
            cout << "  WARNING: resistance " << r
                 << " Ohm tidak valid untuk " << partNumber
                 << " - diabaikan." << endl;
        }
    }

    // Getter (const): baca data tanpa mengubah object
    double getResistance() const { return resistance; }
    double getTolerance()  const { return tolerance;  }
    string getPartNumber() const { return partNumber; }

    // printInfo (const): tidak mengubah object
    void printInfo() const {
        cout << "  [" << partNumber << "] "
             << resistance << " Ohm +/- " << tolerance << "%" << endl;
    }
};

int main() {
    cout << "==========================================\n";
    cout << " Week 12 Demo 02 - Enkapsulasi           \n";
    cout << "==========================================\n";

    section("1. Konstruksi object Resistor (valid)");
    Resistor r1("R-470",  470.0, 1.0);   // resistance 470 Ohm, toleransi 1%
    Resistor r2("R-1k",  1000.0);        // toleransi default = 5%
    r1.printInfo();
    r2.printInfo();

    section("2. Konstruksi dengan resistance negatif (ditolak)");
    Resistor r3("R-BAD", -50.0);         // setter memperingatkan dan menolak
    r3.printInfo();                       // resistance tetap 0.0

    section("3. Mengubah resistance via setter");
    cout << "  r2 sebelum: ";
    r2.printInfo();
    r2.setResistance(2200.0);            // valid: diterima
    cout << "  r2 sesudah setResistance(2200): ";
    r2.printInfo();
    r2.setResistance(-1.0);              // invalid: ditolak
    cout << "  r2 sesudah setResistance(-1): ";
    r2.printInfo();

    section("4. Akses langsung ke private member");
    cout << "  Baris berikut adalah compile error (dikomentar):" << endl;
    // r1.resistance = 100;   // error: resistance is private
    // r1.partNumber = "X";   // error: partNumber is private
    cout << "  // r1.resistance = 100;  <-- compile error!" << endl;
    cout << "  Gunakan getter: r1.getResistance() = "
         << r1.getResistance() << " Ohm" << endl;

    cout << "\n  Selesai.\n";
    return 0;
}
