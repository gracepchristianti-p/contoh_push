#include <iostream>
#include <string>
using namespace std;

int main() {
    string merk[5], model[5], warna[5];
    int tahun[5], harga[5], jumlah = 0, pil;
    
    merk[0] = "Mitsubishi"; model[0] = "Xpander"; warna[0] = "Merah"; tahun[0] = 2024; harga[0] = 280;
    merk[1] = "Daihatsu"; model[1] = "Xenia"; warna[1] = "Abu-abu"; tahun[1] = 2023; harga[1] = 220;
    merk[2] = "Mazda"; model[2] = "CX-5"; warna[2] = "Biru"; tahun[2] = 2024; harga[2] = 520;
    jumlah = 3;
    
    do {
        cout << endl << "=== SHOWROOM MOBIL ===" << endl;
        cout << "1. Lihat  2. Tambah  3. Cari  4. Exit" << endl;
        cout << "Pilih: "; cin >> pil;
        
        if(pil == 1) {
            cout << endl << "DAFTAR MOBIL:" << endl;
            for(int i = 0; i < jumlah; i++)
                cout << i+1 << ". " << merk[i] << " " << model[i] << " (" << warna[i] << ", " << tahun[i] << ") - " << harga[i] << " Jt" << endl;
        }
        else if(pil == 2) {
            if(jumlah >= 5) cout << endl << "Penuh!" << endl;
            else {
                cin.ignore();
                cout << endl << "Merk: "; getline(cin, merk[jumlah]);
                cout << "Model: "; getline(cin, model[jumlah]);
                cout << "Warna: "; getline(cin, warna[jumlah]);
                cout << "Tahun: "; cin >> tahun[jumlah];
                cout << "Harga: "; cin >> harga[jumlah];
                jumlah++;
                cout << "Ditambahkan!" << endl;
            }
        }
        else if(pil == 3) {
            int max, i = 0;
            bool ada = false;
            cout << endl << "Max harga: "; cin >> max;
            cout << "Hasil:" << endl;
            while(i < jumlah) {
                if(harga[i] <= max) {
                    cout << merk[i] << " " << model[i] << " - " << harga[i] << " Jt" << endl;
                    ada = true;
                }
                i++;
            }
            if(!ada) cout << "Tidak ada." << endl;
        }
        else if(pil == 4) cout << endl << "Terima kasih!" << endl;
        else cout << endl << "Salah!" << endl;
        
    } while(pil != 4);
    
    return 0;
}