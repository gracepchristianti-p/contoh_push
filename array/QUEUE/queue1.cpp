#include <iostream>
using namespace std;

#define MAX 10  
struct Queue {
    int data[MAX];
    int front;
    int rear;
    int count;
};


void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}


bool isFull(Queue q) {
    return q.count == MAX;
}


bool isEmpty(Queue q) {
    return q.count == 0;
}


void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa enqueue." << endl;
        return;
    }
    
    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = value;
    q.count++;
    
    cout << "Enqueue: " << value << " berhasil ditambahkan!" << endl;
}


int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak bisa dequeue." << endl;
        return -1;
    }
    
    int value = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;
    
    return value;
}


void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    
    cout << "\nIsi Queue: ";
    int idx = q.front;
    
    for (int i = 0; i < q.count; i++) {
        cout << q.data[idx] << " ";
        idx = (idx + 1) % MAX;
    }
    
    cout << endl;
}

int main() {
    Queue q;
    init(q);
    
    int pilihan, nilai;
    
    do {
        cout << "\n=== MENU PROGRAM QUEUE ===" << endl;
        cout << "1. Enqueue (Tambah elemen)" << endl;
        cout << "2. Dequeue (Hapus elemen)" << endl;
        cout << "3. Display (Tampilkan isi queue)" << endl;
        cout << "4. Cek isEmpty" << endl;
        cout << "5. Cek isFull" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueue(q, nilai);
                break;
                
            case 2:
                nilai = dequeue(q);
                if (nilai != -1) {
                    cout << "Elemen dequeue: " << nilai << endl;
                }
                break;
                
            case 3:
                display(q);
                break;
                
            case 4:
                if (isEmpty(q)) {
                    cout << "Queue KOSONG" << endl;
                } else {
                    cout << "Queue TIDAK KOSONG" << endl;
                }
                break;
                
            case 5:
                if (isFull(q)) {
                    cout << "Queue PENUH" << endl;
                } else {
                    cout << "Queue TIDAK PENUH" << endl;
                }
                break;
                
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
    } while (pilihan != 0);
    
    return 0;
}
