// 04_ee_adc_calibration.cpp — aplikasi EE: tabel kalibrasi ADC
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo04 src/search_ops.cpp src/04_ee_adc_calibration.cpp
// Run:     ./demo04
#include "search_ops.h"

// Struktur titik kalibrasi ADC
struct CalPoint {
    int   raw;         // nilai raw ADC (0-4095 untuk 12-bit)
    float voltage_mV;  // tegangan terukur dalam miliVolt
};

// Cari titik kalibrasi menggunakan binary search pada field raw
int calSearch(const vector<CalPoint>& table, int rawADC) {
    int lo = 0, hi = (int)table.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if      (table[mid].raw == rawADC) return mid;  // cocok tepat
        else if (table[mid].raw <  rawADC) lo = mid + 1; // ke kanan
        else                               hi = mid - 1; // ke kiri
    }
    return -1; // tidak ditemukan (antara dua titik kalibrasi)
}

// Interpolasi linear antara dua titik kalibrasi terdekat
float interpolate(const vector<CalPoint>& table, int rawADC) {
    // Cari batas bawah dengan lower_bound
    auto cmp = [](const CalPoint& p, int val){ return p.raw < val; };
    auto it  = lower_bound(table.begin(), table.end(), rawADC, cmp);
    if (it == table.end())   return table.back().voltage_mV;
    if (it == table.begin()) return table.front().voltage_mV;
    // Interpolasi linear antara it-1 dan it
    auto prev = it - 1;
    float ratio = (float)(rawADC - prev->raw) / (it->raw - prev->raw);
    return prev->voltage_mV + ratio * (it->voltage_mV - prev->voltage_mV);
}

int main() {
    cout << "==========================================\n";
    cout << " Demo 04: EE — Kalibrasi ADC             \n";
    cout << "==========================================\n";

    // Tabel kalibrasi ADC 12-bit (0-4095) ke tegangan (mV)
    // Diurutkan berdasarkan raw ADC — syarat untuk binary search
    vector<CalPoint> calTable = {
        {   0,    0.0f},
        { 512,  400.0f},
        {1024,  805.0f},
        {2048, 1610.0f},
        {3072, 2415.0f},
        {4095, 3300.0f}
    };

    section("Tabel Kalibrasi ADC");
    cout << "  raw_ADC | voltage_mV\n";
    cout << "  --------|----------\n";
    for (auto& p : calTable)
        cout << "  " << p.raw << "\t| " << p.voltage_mV << "\n";

    section("Pencarian Titik Kalibrasi Tepat (Binary Search)");
    vector<int> queries = {0, 1024, 2048, 4095};
    for (int q : queries) {
        int idx = calSearch(calTable, q);
        if (idx != -1)
            cout << "  ADC raw=" << q << " -> "
                 << calTable[idx].voltage_mV << " mV (tepat)\n";
    }

    section("Interpolasi Linear untuk Nilai di Antara Titik");
    vector<int> rawSamples = {256, 768, 1500, 3500};
    for (int r : rawSamples) {
        float v = interpolate(calTable, r);
        cout << "  ADC raw=" << r << " -> " << v << " mV (interpolasi)\n";
    }

    section("Konteks EE");
    cout << "  ADC 12-bit : resolusi = 3300mV / 4095 = ~0.806 mV/count\n";
    cout << "  Binary search memungkinkan lookup O(log n) pada tabel besar\n";
    cout << "  Interpolasi linear memberikan akurasi antara titik kalibrasi\n";

    cout << "\n  Selesai.\n";
    return 0;
}
