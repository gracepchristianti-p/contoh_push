#include <iostream>
using namespace std;

struct MataKuliah {
    string kode;
    string nama;
    int sks;
    string dosen;
};

int main() {
    MataKuliah mk[100];
    int jumlah = 0;
    int pilihan;

    do {
        cout << "\n=== SISTEM PERKULIAHAN ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Lihat Data\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Cari Data (Get By ID)\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        // 1. CREATE
        if (pilihan == 1) {
            cout << "\nTambah Data Mata Kuliah\n";
            cout << "Kode MK  : ";
            cin >> mk[jumlah].kode;
            cin.ignore();
            cout << "Nama MK  : ";
            getline(cin, mk[jumlah].nama);
            cout << "SKS      : ";
            cin >> mk[jumlah].sks;
            cin.ignore();
            cout << "Dosen    : ";
            getline(cin, mk[jumlah].dosen);

            jumlah++;
            cout << "Data berhasil ditambahkan!\n";
        }

        // 2. READ (ALL)
        else if (pilihan == 2) {
            if (jumlah == 0) {
                cout << "Data masih kosong!\n";
            } else {
                cout << "\nDaftar Mata Kuliah\n";
                for (int i = 0; i < jumlah; i++) {
                    cout << "\nData ke-" << i + 1 << endl;
                    cout << "Kode  : " << mk[i].kode << endl;
                    cout << "Nama  : " << mk[i].nama << endl;
                    cout << "SKS   : " << mk[i].sks << endl;
                    cout << "Dosen : " << mk[i].dosen << endl;
                }
            }
        }

        // 3. UPDATE
        else if (pilihan == 3) {
            string cari;
            cout << "Masukkan kode MK yang mau diubah: ";
            cin >> cari;

            bool ketemu = false;
            for (int i = 0; i < jumlah; i++) {
                if (mk[i].kode == cari) {
                    cin.ignore();
                    cout << "Nama MK baru  : ";
                    getline(cin, mk[i].nama);
                    cout << "SKS baru      : ";
                    cin >> mk[i].sks;
                    cin.ignore();
                    cout << "Dosen baru    : ";
                    getline(cin, mk[i].dosen);

                    cout << "Data berhasil diubah!\n";
                    ketemu = true;
                    break;
                }
            }

            if (!ketemu) {
                cout << "Data tidak ditemukan!\n";
            }
        }

        // 4. DELETE
        else if (pilihan == 4) {
            string cari;
            cout << "Masukkan kode MK yang mau dihapus: ";
            cin >> cari;

            bool ketemu = false;
            for (int i = 0; i < jumlah; i++) {
                if (mk[i].kode == cari) {
                    for (int j = i; j < jumlah - 1; j++) {
                        mk[j] = mk[j + 1];
                    }
                    jumlah--;
                    cout << "Data berhasil dihapus!\n";
                    ketemu = true;
                    break;
                }
            }

            if (!ketemu) {
                cout << "Data tidak ditemukan!\n";
            }
        }

        // 5. GET BY ID
        else if (pilihan == 5) {
            string cari;
            cout << "Masukkan kode MK yang dicari: ";
            cin >> cari;

            bool ketemu = false;
            for (int i = 0; i < jumlah; i++) {
                if (mk[i].kode == cari) {
                    cout << "\nData Mata Kuliah Ditemukan\n";
                    cout << "Kode  : " << mk[i].kode << endl;
                    cout << "Nama  : " << mk[i].nama << endl;
                    cout << "SKS   : " << mk[i].sks << endl;
                    cout << "Dosen : " << mk[i].dosen << endl;
                    ketemu = true;
                    break;
                }
            }

            if (!ketemu) {
                cout << "Data tidak ditemukan!\n";
            }
        }

        // 6. EXIT
        else if (pilihan == 6) {
            cout << "Program selesai. Sampai jumpa 👋\n";
        }

        else {
            cout << "Pilihan ga valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}
