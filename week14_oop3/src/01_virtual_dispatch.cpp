// 01_virtual_dispatch.cpp — demo virtual keyword: runtime dispatch
// ENEE602004 Algoritma Pemrograman dan Praktikum
// Dr. Alfan Presekal — Universitas Indonesia
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo01 src/01_virtual_dispatch.cpp
// Run:     ./demo01
#include <iostream>
using namespace std;

// ── TANPA virtual ─────────────────────────────────────────────
// Base pointer → selalu panggil versi Base (SALAH!)
struct ShapeA {
    void describe() const {          // BUKAN virtual
        cout << "  [ShapeA] Bentuk generik" << endl;
    }
};
struct CircleA : ShapeA {
    void describe() const {          // hide, BUKAN override
        cout << "  [CircleA] Lingkaran" << endl;
    }
};

// ── DENGAN virtual ────────────────────────────────────────────
// Base pointer → panggil versi yang SESUAI tipe objek sebenarnya
struct ShapeB {
    virtual void describe() const {  // virtual → runtime dispatch
        cout << "  [ShapeB] Bentuk generik" << endl;
    }
    virtual ~ShapeB() = default;
};
struct CircleB : ShapeB {
    void describe() const override { // override dari ShapeB
        cout << "  [CircleB] Lingkaran — dispatch BENAR!" << endl;
    }
};
struct RectangleB : ShapeB {
    void describe() const override {
        cout << "  [RectangleB] Persegi panjang — dispatch BENAR!" << endl;
    }
};

int main() {
    cout << "=== Demo 01: Virtual Dispatch ===" << endl;

    // ── Tanpa virtual ─────────────────────────────────────────
    cout << "\n[TANPA virtual] — base pointer selalu panggil Base:" << endl;
    ShapeA* p1 = new CircleA();
    p1->describe();   // memanggil ShapeA::describe() — SALAH!
    delete p1;

    // ── Dengan virtual ────────────────────────────────────────
    cout << "\n[DENGAN virtual] — base pointer panggil versi turunan:" << endl;
    ShapeB* shapes[2];
    shapes[0] = new CircleB();
    shapes[1] = new RectangleB();
    for (int i = 0; i < 2; i++) {
        shapes[i]->describe();   // vtable → dispatch ke implementasi yang tepat
        delete shapes[i];
    }

    cout << "\nKesimpulan: tambahkan 'virtual' agar pointer base" << endl;
    cout << "            memanggil implementasi kelas turunan." << endl;
    return 0;
}
