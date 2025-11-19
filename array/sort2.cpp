#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) {
    int i = left;      
    int j = mid + 1;   
    int k = 0;         
    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {   
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }


    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }


    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }


    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;


        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);


        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan nilai-nilai array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);


    cout << "\nArray setelah diurutkan (descending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
