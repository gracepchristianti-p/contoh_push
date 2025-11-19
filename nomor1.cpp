#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilai;
};

int main() {
    Mahasiswa mhs1;
    Mahasiswa mhs2;

    cout << "======================================================" << endl;
    mhs1.nama = "Grace Praisa Christianti";
    mhs1.nim = "20250803011";
    mhs1.nilai = 95.5;

    cout << "Nama: " << mhs1.nama << endl;
    cout << "NIM: " << mhs1.nim << endl;
    cout << "Nilai: " << mhs1.nilai << endl;

    cout << "======================================================" << endl;   
    mhs2.nama = "John Doe";
    mhs2.nim = "20250803012";   
    mhs2.nilai = 88.0;  
    
    cout << "Nama: " << mhs2.nama << endl;
    cout << "NIM: " << mhs2.nim << endl;
    cout << "Nilai: " << mhs2.nilai << endl;

    return 0;
}