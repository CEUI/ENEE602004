// 03_access_specifiers.cpp - public/protected/private + upcasting + virtual dispatch
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo03 src/03_access_specifiers.cpp
// Run:     ./demo03
#include "oop2.h"

// Demo access specifiers: tiga level akses
class AccessDemo {
public:
    int pubVal = 10;       // dapat diakses dari mana saja
protected:
    int protVal = 20;      // hanya dari class ini dan turunannya
private:
    int privVal = 30;      // hanya dari class ini sendiri

public:
    void showAll() const {
        // Di dalam class: semua level dapat diakses
        cout << "  public=" << pubVal
             << "  protected=" << protVal
             << "  private=" << privVal << endl;
    }
};

class AccessChild : public AccessDemo {
public:
    void tryAccess() const {
        cout << "  Child bisa akses public   : " << pubVal   << endl;
        cout << "  Child bisa akses protected: " << protVal  << endl;
        // cout << privVal;  // ERROR: privVal is private
        cout << "  Child TIDAK bisa akses private (compile error jika dicoba)" << endl;
    }
};

// Kelas untuk demo upcasting dan virtual dispatch
class Resistor : public Component {
protected:
    double resistance;
public:
    Resistor(const string& pn, double r)
        : Component(pn), resistance(r) {}
    ~Resistor() override {}
    void printInfo() const override {
        cout << "  Resistor [" << partNumber << "]: "
             << resistance << " Ohm" << endl;
    }
};

class Capacitor : public Component {
private:
    double capacitance;
public:
    Capacitor(const string& pn, double c)
        : Component(pn), capacitance(c) {}
    ~Capacitor() override {}
    void printInfo() const override {
        cout << "  Capacitor [" << partNumber << "]: "
             << capacitance * 1e6 << " uF" << endl;
    }
};

int main() {
    cout << "==========================================\n";
    cout << " Week 13 Demo 03 - Access Specifiers     \n";
    cout << "==========================================\n";

    // Access specifiers
    section("1. public / protected / private");
    AccessDemo ad;
    ad.showAll();
    cout << "  Luar class bisa akses pubVal  : " << ad.pubVal << endl;
    // ad.protVal = 5;  // ERROR: protected
    // ad.privVal = 5;  // ERROR: private
    cout << "  Luar class TIDAK bisa akses protected/private" << endl;

    AccessChild ac;
    ac.tryAccess();

    // Upcasting: pointer Component* ke object turunan
    section("2. Upcasting - Component* menunjuk ke object turunan");
    Component* parts[3];
    parts[0] = new Resistor ("R-220",  220.0);
    parts[1] = new Capacitor("C-47uF",  47e-6);
    parts[2] = new Resistor ("R-4k7", 4700.0);

    cout << "\n  Virtual dispatch - printInfo() via Component*:" << endl;
    for (int i = 0; i < 3; i++) {
        parts[i]->printInfo();   // memanggil versi override, bukan Component::printInfo
    }

    // Virtual destructor
    section("3. Virtual destructor - penting saat delete via pointer");
    cout << "  Menghapus via Component* (virtual dtor memastikan cleanup benar):" << endl;
    for (int i = 0; i < 3; i++) {
        delete parts[i];  // ~Resistor / ~Capacitor berjalan, bukan hanya ~Component
    }
    cout << "  Tanpa virtual dtor: hanya ~Component yang berjalan!" << endl;

    cout << "\n  Selesai.\n";
    return 0;
}
