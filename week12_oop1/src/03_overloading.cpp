// 03_overloading.cpp - Constructor overloading (Capacitor) + Method overloading (ADCSensor)
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal - Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo03 src/03_overloading.cpp
// Run:     ./demo03
#include "oop1.h"

// Class Capacitor - constructor overloading
// Tiga constructor: compiler memilih berdasarkan argumen yang diberikan
class Capacitor {
private:
    string partNumber;
    double capacitance;    // Farad
    double voltageRating;  // Volt

public:
    // Constructor overload 1: spesifikasi lengkap (3 argumen)
    Capacitor(const string& pn, double c, double vRating)
        : partNumber(pn), capacitance(c), voltageRating(vRating)
    {
        cout << "  [Capacitor dibuat] " << partNumber
             << " - full constructor" << endl;
    }

    // Constructor overload 2: voltage rating default 50V (2 argumen)
    Capacitor(const string& pn, double c)
        : partNumber(pn), capacitance(c), voltageRating(50.0)
    {
        cout << "  [Capacitor dibuat] " << partNumber
             << " - default 50V rating" << endl;
    }

    // Constructor overload 3: default semua (0 argumen)
    Capacitor()
        : partNumber("C-GENERIC"), capacitance(0.0), voltageRating(50.0)
    {
        cout << "  [Capacitor dibuat] default (C-GENERIC)" << endl;
    }

    void printInfo() const {
        cout << "  [" << partNumber << "] "
             << capacitance * 1e6 << " uF, "
             << voltageRating << " V rated" << endl;
    }
};

// Class ADCSensor - method overloading
// Tiga method readValue dengan nama sama tapi parameter berbeda
class ADCSensor {
private:
    string name;
    int    resolution;  // bit (misal: 12 untuk ADC 12-bit)
    float  vRef;        // tegangan referensi (Volt)

public:
    ADCSensor(const string& n, int res, float vref)
        : name(n), resolution(res), vRef(vref) {}

    // Method overload 1: kembalikan nilai raw integer (tanpa argumen)
    int readValue() const {
        return 2048;  // simulasi: titik tengah ADC 12-bit
    }

    // Method overload 2: konversi ke tegangan, pakai vRef tersimpan
    float readValue(bool asVoltage) const {
        if (!asVoltage) return (float)readValue();
        int maxVal = (1 << resolution) - 1;  // 2^resolution - 1
        return (readValue() / (float)maxVal) * vRef;
    }

    // Method overload 3: konversi ke tegangan, vRef kustom dari pemanggil
    float readValue(float customVRef) const {
        int maxVal = (1 << resolution) - 1;
        return (readValue() / (float)maxVal) * customVRef;
    }

    void printInfo() const {
        cout << "  " << name << ": " << resolution << "-bit ADC"
             << ", Vref=" << vRef << "V" << endl;
    }
};

int main() {
    cout << "==========================================\n";
    cout << " Week 12 Demo 03 - Overloading           \n";
    cout << "==========================================\n";

    // Constructor overloading: Capacitor
    section("1. Constructor overloading - Capacitor");
    Capacitor c1("C-100nF", 100e-9, 16.0);  // overload 1: full
    Capacitor c2("C-10uF",   10e-6);         // overload 2: default voltage
    Capacitor c3;                             // overload 3: default semua
    cout << endl;
    c1.printInfo();
    c2.printInfo();
    c3.printInfo();

    // Method overloading: ADCSensor
    section("2. Method overloading - ADCSensor (readValue)");
    ADCSensor adc("ADC-CH0", 12, 5.0f);
    adc.printInfo();
    cout << endl;

    int   raw   = adc.readValue();        // overload 1: tanpa argumen
    float volt  = adc.readValue(true);    // overload 2: bool
    float volt2 = adc.readValue(3.3f);    // overload 3: float custom vRef

    cout << "  readValue()       = " << raw   << " (raw ADC)" << endl;
    cout << "  readValue(true)   = " << volt  << " V (vRef=5V tersimpan)" << endl;
    cout << "  readValue(3.3f)   = " << volt2 << " V (vRef=3.3V kustom)" << endl;

    cout << "\n  Selesai.\n";
    return 0;
}
