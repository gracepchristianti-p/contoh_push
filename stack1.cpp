#include <iostream>
using namespace std;

int topIndex = -1;   
int capacity;        
int *stackArr;       


bool isFull() {
    return topIndex == capacity - 1;
}

bool isEmpty() {
    return topIndex == -1;
}

void push(int data) {
    if (isFull()) {
        cout << "Stack penuh! Tidak bisa menambah data.\n";
    } else {
        topIndex++;
        stackArr[topIndex] = data;
        cout << data << " berhasil ditambahkan ke stack.\n";
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada data yang bisa dihapus.\n";
    } else {
        cout << "Data " << stackArr[topIndex] << " dihapus dari stack.\n";
        topIndex--;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada elemen teratas.\n";
    } else {
        cout << "Elemen paling atas: " << stackArr[topIndex] << endl;
    }
}

void size() {
    cout << "Jumlah elemen dalam stack: " << (topIndex + 1) << endl;
}

// ---- MAIN PROGRAM ----
int main() {
    cout << "Masukkan kapasitas maksimal stack: ";
    cin >> capacity;

    stackArr = new int[capacity]; 

    int pilihan, data;

    do {
        cout << "\n==== MENU STACK ====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. IsEmpty\n";
        cout << "5. Size\n";
        cout << "6. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                if (isEmpty()) cout << "Stack dalam keadaan KOSONG.\n";
                else cout << "Stack TIDAK kosong.\n";
                break;

            case 5:
                size();
                break;

            case 6:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    delete[] stackArr;
    return 0;
}
