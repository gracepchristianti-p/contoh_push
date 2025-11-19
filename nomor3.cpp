#include <iostream>
#include <string>
using namespace std;

struct Alamat {
    string kota;
    string provinsi;
};

struct Mahasiswa {
    string nama_mahasiswa;
    int NIM_mahasiswa;
    Alamat alamat_mahasiswa; 
};

int main() {
    Mahasiswa mhs;

    cout << "==== Input Data Mahasiswa ====" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama_mahasiswa);

    cout << "Masukkan NIM: ";
    cin >> mhs.NIM_mahasiswa;
    cin.ignore(); 

    cout << "Masukkan Kota: ";
    getline(cin, mhs.alamat_mahasiswa.kota);

    cout << "Masukkan Provinsi: ";
    getline(cin, mhs.alamat_mahasiswa.provinsi);

    cout << "==== Data Mahasiswa ====" << endl;
    cout << "Nama      : " << mhs.nama_mahasiswa << endl;
    cout << "NIM       : " << mhs.NIM_mahasiswa << endl;
    cout << "Kota      : " << mhs.alamat_mahasiswa.kota << endl;
    cout << "Provinsi  : " << mhs.alamat_mahasiswa.provinsi << endl;

    return 0;
}
