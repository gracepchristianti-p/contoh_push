#include <iostream>
using namespace std;

int main () {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    bool genap = (angka % 2 == 0);
    cout << "Apakah genap? " << (genap ? "Ya" : "Tidak") << endl;
    return 0;
}