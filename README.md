# ENEE602004 — Algoritma Pemrograman dan Praktikum

Materi kuliah dan kode demo untuk mata kuliah **ENEE602004 Algoritma Pemrograman dan Praktikum**  
Teknik Elektro · Universitas Indonesia

**Dosen:** Dr. Alfan Presekal

---

## Struktur Materi

| Folder | Topik | Konsep Utama |
|--------|-------|--------------|
| `week09_linked_list/` | Linked List | Node, pointer, SLL: append, prepend, insert, delete |
| `week10_searching/` | Searching Algorithms | Linear Search O(n), Binary Search O(log n), STL |
| `week11_sorting/` | Sorting Algorithms | Bubble, Insertion, Selection Sort, std::sort |
| `week12_oop1/` | OOP (1) | Class, abstraction, encapsulation, constructor |
| `week13_oop2/` | OOP (2) | Inheritance, IS-A, override, constructor/destructor chain |
| `week14_oop3/` | OOP (3) | Virtual, abstract class, polymorphism, unique_ptr |
| `week15_sockets/` | Network Sockets | TCP/UDP, client-server, POSIX sockets |

---

## Struktur Setiap Folder

```
weekXX_topic/
├── weekXX_topic.md   # Materi slide (Markdown)
├── Makefile          # Build semua demo sekaligus
├── src/              # Source code C++
│   ├── topicXX.h             # Header utama
│   ├── 01_demo.cpp           # Demo 1
│   ├── 02_demo.cpp           # Demo 2
│   ├── 03_demo.cpp           # Demo 3
│   └── 04_ee_application.cpp # Demo aplikasi EE
└── img/              # Ilustrasi (PNG)
```

---

## Cara Kompilasi

**Kompilasi semua demo sekaligus (gunakan Makefile):**
```bash
cd weekXX_topic
make
```

**Atau kompilasi manual:**
```bash
g++ -std=c++17 -Wall -Isrc -o demo01 src/01_demo.cpp
./demo01
```

> Semua demo dikompilasi dengan `g++ -std=c++17`. Pastikan `g++` sudah terinstal.  
> Untuk week15 (sockets), kompilasi di Linux/WSL karena menggunakan POSIX API.

---

## Prasyarat

- Compiler: `g++` dengan dukungan C++17
- OS: Linux, WSL (Windows Subsystem for Linux), atau macOS
- Week 15 (Sockets): POSIX-compatible environment (Linux/WSL)

---

## Lisensi

Materi ini digunakan untuk keperluan pendidikan di lingkungan Universitas Indonesia.
