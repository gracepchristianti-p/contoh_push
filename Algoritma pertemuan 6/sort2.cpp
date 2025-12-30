#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;


void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partisi(int arr[], int kiri, int kanan) {
    int pivot = arr[kanan]; 
    int i = kiri - 1;

    for (int j = kiri; j < kanan; j++) {
        if (arr[j] < pivot) { 
            i++;
            tukar(arr[i], arr[j]);
        }
    }

    tukar(arr[i + 1], arr[kanan]);
    return i + 1;
}


void quickSort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int pi = partisi(arr, kiri, kanan);
        quickSort(arr, kiri, pi - 1);  
        quickSort(arr, pi + 1, kanan); 
    }
}

int main() {
    const int n = 10;
    int arr[n];

    srand(time(0)); 

    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }

        cout << "Bilangan sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

        quickSort(arr, 0, n - 1);

    
    cout << "\nBilangan setelah diurutkan (ascending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

