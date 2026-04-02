// ============================================================
// 04_ee_sensor.cpp — Aplikasi EE: Log Sensor ADC
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Linked list sebagai buffer log pembacaan sensor ADC.
// Setiap pembacaan di-prepend → kepala list = data terbaru.
//
// Kompilasi:
//   g++ -std=c++17 -Wall -o demo04 sll_ops.cpp 04_ee_sensor.cpp
// Jalankan:
//   ./demo04
// ============================================================
#include "sll_ops.h"

// Node khusus untuk data sensor (berbeda dari Node integer biasa)
struct SensorNode {
    float       voltage;   // tegangan hasil konversi ADC (Volt)
    int         channel;   // nomor channel ADC
    SensorNode* next;

    SensorNode(float v, int ch) : voltage(v), channel(ch), next(nullptr) {}
};

// Cetak seluruh log sensor dari head ke akhir
void printSensorLog(SensorNode* head) {
    int idx = 0;
    for (SensorNode* c = head; c != nullptr; c = c->next, idx++)
        cout << "  [" << idx << "] CH" << c->channel
             << " = " << c->voltage << " V" << endl;
}

// Bebaskan memori log sensor
void freeSensorLog(SensorNode*& head) {
    while (head) {
        SensorNode* tmp = head->next;
        delete head;
        head = tmp;
    }
}

int main() {
    cout << "============================================" << endl;
    cout << " Demo 04: Aplikasi EE — Log Sensor ADC    " << endl;
    cout << "============================================" << endl;

    SensorNode* log_head = nullptr;

    // ── Simulasi pembacaan ADC dari 5 channel ────────────────
    // readings[i] = tegangan dari channel ke-i
    // Setiap pembacaan di-prepend → kepala list = data terbaru
    float readings[] = {1.2f, 2.5f, 3.3f, 0.8f, 3.1f};
    int   channels[] = {0,    1,    2,    3,    4   };

    section("Masukkan 5 pembacaan ADC (prepend tiap pembacaan)");
    for (int i = 0; i < 5; i++) {
        SensorNode* n = new SensorNode(readings[i], channels[i]);
        n->next   = log_head;    // node baru → log sebelumnya
        log_head  = n;           // head = node terbaru
        cout << "  Tambah CH" << channels[i]
             << " = " << readings[i] << " V" << endl;
    }

    // ── Cetak log (terbaru pertama karena prepend) ────────────
    section("Log pembacaan (terbaru di atas)");
    printSensorLog(log_head);

    // ── Simulasi: hapus pembacaan terlama (ekor list) ─────────
    // Untuk linked list, hapus ekor perlu traversal O(n).
    // Jika sering hapus ekor, lebih baik pakai doubly linked list.
    section("Hapus pembacaan terlama (ekor = CH0)");
    SensorNode* prev = nullptr;
    SensorNode* curr = log_head;
    while (curr->next != nullptr) { prev = curr; curr = curr->next; }
    if (prev) { prev->next = nullptr; delete curr; }
    else       { delete log_head; log_head = nullptr; }

    printSensorLog(log_head);

    // ── Tambah pembacaan baru ─────────────────────────────────
    section("Pembacaan baru: CH5 = 4.7 V (prepend)");
    SensorNode* newest = new SensorNode(4.7f, 5);
    newest->next = log_head;
    log_head     = newest;
    printSensorLog(log_head);

    // ── Bebaskan memori ───────────────────────────────────────
    freeSensorLog(log_head);
    cout << "\n  Memori log sensor dibebaskan. Selesai." << endl;
    return 0;
}
