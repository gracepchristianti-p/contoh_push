#include <iostream>
using namespace std;

#define MAX 5   // Ukuran queue kecil agar mudah melihat perputaran

struct Queue {
    char data[MAX];
    int front;
    int rear;
    int count; // jumlah elemen
};

// Inisialisasi Queue
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Cek kosong
bool isEmpty(Queue *q) {
    return q->count == 0;
}

// Cek penuh
bool isFull(Queue *q) {
    return q->count == MAX;
}

// Insert circular
void insert(Queue *q, char value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak dapat insert " << value << endl;
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = value;
        q->count++;
        cout << "Inserted: " << value << endl;
    }
}

// Remove circular
void remove(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak dapat remove\n";
    } else {
        char value = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        cout << "Removed: " << value << endl;
    }
}

// Display circular
void display(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Isi Queue: ";

    int i = q->front;
    for (int c = 0; c < q->count; c++) {
        cout << q->data[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    Queue q;
    init(&q);

    cout << "=== PROGRAM QUEUE CIRCULAR ARRAY ===\n\n";

    cout << "1. Mengisi queue hingga penuh:\n";
    insert(&q, 'A');
    insert(&q, 'B');
    insert(&q, 'C');
    insert(&q, 'D');
    insert(&q, 'E'); // Queue penuh
    insert(&q, 'F'); // Tidak bisa

    cout << "\n2. Menghapus 3 elemen:\n";
    remove(&q);
    remove(&q);
    remove(&q);

    cout << "\n3. Mengisi 2 elemen baru:\n";
    insert(&q, 'X');
    insert(&q, 'Y');

    cout << "\n4. Posisi front dan rear:\n";
    cout << "Front = " << q.front << endl;
    cout << "Rear  = " << q.rear << endl;

    cout << "\n5. Menampilkan isi queue:\n";
    display(&q);

    return 0;
}
