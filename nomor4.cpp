#include <iostream>
#include <string>
using namespace std;


struct Alamat {
    string kota;
    string provinsi;
};


struct Mahasiswa {
    string nama;
    string nim;
    Alamat alamat;
};


void tampilData(Mahasiswa mhs) {
    cout << "===== Data Mahasiswa =====" << endl;
    cout << "Nama      : " << mhs.nama << endl;
    cout << "NIM       : " << mhs.nim << endl;
    cout << "Kota      : " << mhs.alamat.kota << endl;
    cout << "Provinsi  : " << mhs.alamat.provinsi << endl;
}

int main() {
    Mahasiswa mhs1, mhs2;

    cout << "===== Input Data Mahasiswa 1 =====" << endl;
    cout << "Masukkan Nama     : ";
    getline(cin, mhs1.nama);
    cout << "Masukkan NIM      : ";
    getline(cin, mhs1.nim);
    cout << "Masukkan Kota     : ";
    getline(cin, mhs1.alamat.kota);
    cout << "Masukkan Provinsi : ";
    getline(cin, mhs1.alamat.provinsi);

    cout << "===== Input Data Mahasiswa 2 =====" << endl;
    cout << "Masukkan Nama     : ";
    getline(cin, mhs2.nama);
    cout << "Masukkan NIM      : ";
    getline(cin, mhs2.nim);
    cout << "Masukkan Kota     : ";
    getline(cin, mhs2.alamat.kota);
    cout << "Masukkan Provinsi : ";
    getline(cin, mhs2.alamat.provinsi);


    tampilData(mhs1);
    tampilData(mhs2);

    return 0;
}
