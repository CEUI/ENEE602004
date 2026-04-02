// 01_basic_class.cpp - BasicResistor: semua member public (tanpa enkapsulasi)
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo01 src/01_basic_class.cpp
// Run:     ./demo01
#include "oop1.h"

// Class BasicResistor - semua member public (tidak terenkapsulasi)
class BasicResistor {
public:
    string partNumber;   // nomor part komponen
    double resistance;   // Ohm - tidak ada validasi!
    double tolerance;    // persen - tidak ada validasi!

    void printInfo() {
        cout << "  [" << partNumber << "] "
             << resistance << " Ohm +/- " << tolerance << "%" << endl;
    }
};

int main() {
    cout << "==========================================\n";
    cout << " Week 12 Demo 01 - Basic Class (Public)  \n";
    cout << "==========================================\n";

    section("1. Penggunaan normal BasicResistor");
    BasicResistor br;
    br.partNumber = "R-470";
    br.resistance = 470.0;
    br.tolerance  = 5.0;
    br.printInfo();

    section("2. Silent bug - akses langsung tanpa validasi");
    br.resistance = -9999.0;  // nilai tidak valid, compiler diam saja!
    cout << "  Setelah br.resistance = -9999.0 (tidak valid):" << endl;
    br.printInfo();            // mencetak data yang salah!

    br.tolerance = 150.0;     // toleransi >100% tidak masuk akal
    cout << "  Setelah br.tolerance = 150.0 (tidak masuk akal):" << endl;
    br.printInfo();

    section("3. Apa yang kita butuhkan?");
    cout << "  - Data PRIVATE: tidak bisa diubah langsung dari luar" << endl;
    cout << "  - Setter dengan validasi: tolak nilai tidak valid" << endl;
    cout << "  - Constructor: inisialisasi otomatis saat object dibuat" << endl;
    cout << "  => Solusi: ENKAPSULASI (lihat demo 02)" << endl;

    cout << "\n  Selesai.\n";
    return 0;
}
