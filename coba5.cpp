#include <iostream>
using namespace std;

int main() {
    // Mendefinisikan enum
    enum Akun {
        Dosen,
        Mahasiswa
    };

    // Menampilkan pilihan ke pengguna
    cout << "Pilih jenis akun:" << endl;
    cout << "1. Esa Unggul" << endl;
    cout << "2. Mahasiswa" << endl;
    cout << "Masukkan pilihan Anda (1/2): ";

    int pilihan;
    cin >> pilihan;

    // Variabel enum untuk menyimpan pilihan
    Akun akun_pengguna;

    // Menentukan pilihan berdasarkan input
    if (pilihan == 1) {
        akun_pengguna = Dosen;
    } else if (pilihan == 2) {
        akun_pengguna = Mahasiswa;
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    cout << endl;
    cout << "tipe data enum (enumeration)" << endl;
    cout << "-----------------------------" << endl;

    // Menampilkan hasil sesuai enum
    if (akun_pengguna == Dosen) {
        cout << "Anda memilih akun: Esa Unggul" << endl;
    } else if (akun_pengguna == Mahasiswa) {
        cout << "Anda memilih akun: Mahasiswa" << endl;
    }

    return 0;
}

