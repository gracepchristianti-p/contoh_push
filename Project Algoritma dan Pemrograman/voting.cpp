#include <iostream>
using namespace std;

int main() {
    string mobil[5] = {"Toyota Avanza", "Honda CR-V", "Mitsubishi Xpander", "Suzuki Ertiga", "Daihatsu Terios"};
    int vote[5] = {0, 0, 0, 0, 0};
    int pilihan, menu;
    
    cout << "=== VOTING SHOWROOM MOBIL ===" << endl;
    
    do {
        cout << endl;
        cout << "1. Vote" << endl;
        cout << "2. Hasil" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> menu;
        
        if (menu == 1) {
            cout << endl << "Daftar Mobil:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i+1 << ". " << mobil[i] << endl;
            }
            cout << "Pilih (1-5): ";
            cin >> pilihan;
            
            if (pilihan >= 1 && pilihan <= 5) {
                vote[pilihan-1]++;
                cout << "Vote berhasil!" << endl;
            }
        }
        else if (menu == 2) {
            cout << endl << "=== HASIL VOTING ===" << endl;
            for (int i = 0; i < 5; i++) {
                cout << mobil[i] << ": " << vote[i] << " vote" << endl;
            }
        }
        
    } while (menu != 3);
    
    cout << endl << "Terima kasih!" << endl;
    return 0;
}