#include <iostream>
using namespace std;


long long faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int n;
    

    cout << "Masukkan bilangan: ";
    cin >> n;
    

    if (n < 0) {
        cout << "Faktorial tidak terdefinisi untuk bilangan negatif!" << endl;
        return 1;
    }

    long long hasil = faktorial(n);
    cout << "Faktorial dari " << n << " adalah " << hasil << endl;
    
    return 0;
}