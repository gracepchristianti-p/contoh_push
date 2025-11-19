#include <iostream>
using namespace std;

int main() {
    float panjang, lebar, luas;

    // Input panjang dan lebar
    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar: ";
    cin >> lebar;

    // Proses menghitung luas
    luas = panjang * lebar;

    // Output hasil luas
    cout << "Luas persegi panjang adalah: " << luas << endl;

    return 0;
}