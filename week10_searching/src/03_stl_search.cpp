// 03_stl_search.cpp — demo fungsi pencarian STL C++
// ENEE602004 Algoritma Pemrograman dan Praktikum
//
// Compile: g++ -std=c++17 -Wall -Isrc -o demo03 src/search_ops.cpp src/03_stl_search.cpp
// Run:     ./demo03
#include "search_ops.h"

int main() {
    cout << "==========================================\n";
    cout << " Demo 03: STL Search Functions           \n";
    cout << "==========================================\n";

    vector<int> data   = {312, 876, 145, 654, 423, 789, 234, 567, 901, 111};
    vector<int> sorted = data;
    sort(sorted.begin(), sorted.end());

    section("std::find — linear search, data tidak perlu terurut");
    // std::find mengembalikan iterator ke elemen pertama yang cocok
    auto it = find(data.begin(), data.end(), 789);
    if (it != data.end())
        cout << "  find(789): index " << distance(data.begin(), it) << "\n";

    it = find(data.begin(), data.end(), 500);
    if (it == data.end())
        cout << "  find(500): tidak ditemukan (iterator == end())\n";

    section("std::binary_search — mengembalikan bool, data HARUS terurut");
    bool found = binary_search(sorted.begin(), sorted.end(), 423);
    cout << "  binary_search(423): " << (found ? "true" : "false") << "\n";

    found = binary_search(sorted.begin(), sorted.end(), 500);
    cout << "  binary_search(500): " << (found ? "true" : "false") << "\n";

    section("std::lower_bound — iterator ke elemen pertama >= target");
    // Berguna untuk pencarian rentang dan penyisipan terurut
    auto pos = lower_bound(sorted.begin(), sorted.end(), 400);
    cout << "  lower_bound(400): nilai pertama >= 400 adalah "
         << *pos << " di index "
         << distance(sorted.begin(), pos) << "\n";

    pos = lower_bound(sorted.begin(), sorted.end(), 423);
    cout << "  lower_bound(423): nilai pertama >= 423 adalah "
         << *pos << " di index "
         << distance(sorted.begin(), pos) << "\n";

    section("Perbandingan Fungsi STL");
    cout << "  std::find          : O(n), data boleh tidak terurut\n";
    cout << "  std::binary_search : O(log n), data HARUS terurut\n";
    cout << "  std::lower_bound   : O(log n), data HARUS terurut\n";

    cout << "\n  Selesai.\n";
    return 0;
}
