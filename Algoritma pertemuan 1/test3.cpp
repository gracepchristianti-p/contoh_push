#include <iostream>
using namespace std;

int main() {
    int angka;

    // Input 
    cout << "Masukkan umur: ";
    cin >> angka;

    //Proses cek ganjil/genap
    if (angka > 18) {
        cout << angka << " anda dewasa." << endl;
    } else 
        cout << angka << " anda belum dewasa" << endl;

        return 0;
    }