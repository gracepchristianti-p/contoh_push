#include <iostream>
using namespace std;

#define MAX 100

// Struktur Queue
struct Queue {
    char data[MAX];
    int front;
    int rear;
};

// Inisialisasi Queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Cek apakah Queue kosong
bool isEmpty(Queue *q) {
    return q->front == -1;
}

// Cek apakah Queue penuh
bool isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Insert elemen ke Queue
void insert(Queue *q, char value) {
    if (isFull(q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
    }
}

// Remove elemen dari Queue
void remove(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
    } else {
        char value = q->data[q->front];
        cout << "Removed: " << value << endl;

        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

// Tampilkan isi Queue
void display(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Isi Queue: ";
        for (int i = q->front; i <= q->rear; i++) {
            cout << q->data[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    init(&q);

    int n;
    cout << "=== Program Queue Character (Input User) ===\n\n";

    // User menginput jumlah data
    cout << "Masukkan jumlah karakter yang ingin dimasukkan: ";
    cin >> n;

    cout << "Masukkan " << n << " karakter:\n";
    for (int i = 0; i < n; i++) {
        char x;
        cout << "Input karakter ke-" << (i + 1) << ": ";
        cin >> x;
        insert(&q, x);
    }

    cout << "\n=== Isi Queue Saat Ini ===\n";
    display(&q);

    // User memilih jumlah elemen yang ingin dihapus
    int del;
    cout << "\nBerapa elemen yang ingin dihapus? ";
    cin >> del;

    for (int i = 0; i < del; i++) {
        remove(&q);
    }

    cout << "\n=== Isi Queue Setelah Penghapusan ===\n";
    display(&q);

    return 0;
}
