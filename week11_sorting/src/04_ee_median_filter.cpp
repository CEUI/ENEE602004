// 04_ee_median_filter.cpp — aplikasi EE: median filter sinyal ADC
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo04 src/sort_ops.cpp src/04_ee_median_filter.cpp
// Run:     ./demo04
#include "sort_ops.h"

// Median filter dengan window size W
// Untuk setiap posisi, urutkan window dan ambil nilai tengah
vector<int> medianFilter(const vector<int>& signal, int W) {
    vector<int> output;
    int half = W / 2;
    for (int i = half; i < (int)signal.size() - half; i++) {
        // Salin window ke buffer sementara
        vector<int> win(signal.begin() + i - half,
                        signal.begin() + i + half + 1);
        sort(win.begin(), win.end());  // urutkan window
        output.push_back(win[half]);   // ambil median (nilai tengah)
    }
    return output;
}

int main() {
    cout << "==========================================\n";
    cout << " Demo 04: EE — Median Filter Sinyal ADC  \n";
    cout << "==========================================\n";

    // Sinyal ADC dengan noise spike (gangguan impulsif)
    // Spike di index 2 (999) dan index 5 (1)
    vector<int> signal = {312, 315, 999, 318, 310, 1, 316, 320, 313, 317};

    section("Sinyal ADC Mentah (dengan noise spike)");
    cout << "  Index : ";
    for (int i = 0; i < (int)signal.size(); i++) cout << i << "    ";
    cout << "\n  Nilai : [ ";
    for (int v : signal) cout << v << " ";
    cout << "]\n";
    cout << "  (Spike di index 2=999 dan index 5=1)\n";

    section("Median Filter Window=3");
    vector<int> filtered3 = medianFilter(signal, 3);
    cout << "  Hasil : [ ";
    for (int v : filtered3) cout << v << " ";
    cout << "]\n";
    cout << "  (Spike dihilangkan, sinyal bersih)\n";

    section("Median Filter Window=5");
    vector<int> filtered5 = medianFilter(signal, 5);
    cout << "  Hasil : [ ";
    for (int v : filtered5) cout << v << " ";
    cout << "]\n";
    cout << "  (Window lebih besar = lebih halus, lebih banyak data hilang)\n";

    section("Cara Kerja Median Filter");
    cout << "  Window=3 di sekitar index 2 (spike=999):\n";
    cout << "    Nilai   : [315, 999, 318]\n";
    cout << "    Diurut  : [315, 318, 999]\n";
    cout << "    Median  :  318  (spike dieliminasi)\n";

    section("Konteks EE");
    cout << "  - Median filter efektif untuk noise impulsif (spike)\n";
    cout << "  - Digunakan di: sensor suhu, tekanan, akselerometer\n";
    cout << "  - Sorting adalah inti dari algoritma median filter\n";
    cout << "  - Trade-off: window besar = noise lebih bersih, latensi tinggi\n";

    cout << "\n  Selesai.\n";
    return 0;
}
