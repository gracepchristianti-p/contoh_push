#include <iostream>
using namespace std;

int main() {
    int angka;

    // Input 
    cout << "Masukkan nilai ujian: ";
    cin >> angka;

    //Proses cek ganjil/genap
    if (angka > 60) {
        cout << angka << " Lulus." << endl;
    } else 
        cout << angka << " Tidak Lulus. " << endl;

        return 0;
    }