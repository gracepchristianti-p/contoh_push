#include <iostream>
using namespace std;

int main() {
    int ab;

    // Input 
    cout << "Masukkan sebuah bilangan: ";
    cin >> ab;

    //Proses cek ganjil/genap
    if (ab % 2 == 0) {
        cout << ab << " adalah bilangan genap." << endl;
    } else 
        cout << ab << " adalah bilangan ganjil." << endl;

        return 0;
    }