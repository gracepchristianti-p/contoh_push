#include <iostream>
using namespace std;

// Fungsi untuk menampilkan data
void tampilData(int data[], int n) {
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
}

// Fungsi Bubble Sort
int bubbleSort(int data[], int n) {
    int langkah = 0;      // menghitung total langkah (perbandingan + pertukaran)
    int tempData[100];

    // Salin data asli agar tidak berubah
    for (int i = 0; i < n; i++)
        tempData[i] = data[i];

    cout << "\nProses Bubble Sort:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            langkah++; // setiap perbandingan dihitung
            cout << "Bandingkan " << tempData[j] << " dan " << tempData[j + 1];
            if (tempData[j] > tempData[j + 1]) {
                cout << " -> Tukar";
                langkah++; // tambahan langkah untuk pertukaran
                int temp = tempData[j];
                tempData[j] = tempData[j + 1];
                tempData[j + 1] = temp;
            }
            cout << endl;
        }
        cout << "Setelah iterasi ke-" << i + 1 << ": ";
        tampilData(tempData, n);
    }

    cout << "\nHasil Bubble Sort (Ascending): ";
    tampilData(tempData, n);
    return langkah;
}

// Fungsi Selection Sort
int selectionSort(int data[], int n) {
    int langkah = 0;
    int tempData[100];

    for (int i = 0; i < n; i++)
        tempData[i] = data[i];

    cout << "\nProses Selection Sort:\n";
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            langkah++; // setiap perbandingan dihitung
            cout << "Bandingkan " << tempData[j] << " dan " << tempData[minIndex] << endl;
            if (tempData[j] < tempData[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = tempData[i];
            tempData[i] = tempData[minIndex];
            tempData[minIndex] = temp;
            langkah++; // hitung 1 langkah tambahan untuk pertukaran
            cout << "Tukar " << tempData[minIndex] << " dan " << tempData[i] << endl;
        }
        cout << "Setelah iterasi ke-" << i + 1 << ": ";
        tampilData(tempData, n);
    }

    cout << "\nHasil Selection Sort (Ascending): ";
    tampilData(tempData, n);
    return langkah;
}

int main() {
    int n;
    int data[100];

    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Masukkan " << n << " angka integer:\n";
    for (int i = 0; i < n; i++)
        cin >> data[i];

    cout << "\nData sebelum diurutkan: ";
    tampilData(data, n);

    // Jalankan Bubble Sort
    int langkahBubble = bubbleSort(data, n);

    // Jalankan Selection Sort
    int langkahSelection = selectionSort(data, n);

    cout << "\nJumlah langkah/perbandingan dan pertukaran:\n";
    cout << "Bubble Sort     : " << langkahBubble << " langkah\n";
    cout << "Selection Sort  : " << langkahSelection << " langkah\n";

    cout << "\nKesimpulan:\n";
    if (langkahBubble < langkahSelection)
        cout << "Bubble Sort lebih efisien pada data ini.\n";
    else if (langkahBubble > langkahSelection)
        cout << "Selection Sort lebih efisien pada data ini.\n";
    else
        cout << "Kedua algoritma memiliki efisiensi yang sama pada data ini.\n";

    return 0;
}
