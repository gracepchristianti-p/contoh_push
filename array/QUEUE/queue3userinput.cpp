#include <iostream>
using namespace std;

#define MAX 5   // ukuran kecil agar mudah melihat perputaran

struct Queue {
    char data[MAX];
    int front;
    int rear;
    int count;
};

// Inisialisasi queue
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isEmpty(Queue *q) {
    return q->count == 0;
}

bool isFull(Queue *q) {
    return q->count == MAX;
}

// Insert circular
void insert(Queue *q, char value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa insert '" << value << "'\n";
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
        cout << "Queue kosong! Tidak bisa remove.\n";
    } else {
        char value = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        cout << "Removed: " << value << endl;
    }
}

// Tampilkan isi queue (modulo)
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

    cout << "=== PROGRAM QUEUE CIRCULAR ARRAY (USER INPUT) ===\n\n";

    // 1. Mengisi queue hingga penuh
    cout << "Masukkan " << MAX << " karakter untuk mengisi queue hingga penuh:\n";
    for (int i = 0; i < MAX; i++) {
        char x;
        cout << "Input karakter ke-" << (i + 1) << ": ";
        cin >> x;
        insert(&q, x);
    }

    cout << "\nQueue saat ini:\n";
    display(&q);

    // 2. Menghapus 3 elemen
    cout << "\nMenghapus 3 elemen...\n";
    for (int i = 0; i < 3; i++) {
        remove(&q);
    }

    cout << "\nQueue setelah remove 3 elemen:\n";
    display(&q);

    // 3. Menambah 2 elemen baru
    cout << "\nMasukkan 2 elemen baru:\n";
    for (int i = 0; i < 2; i++) {
        char x;
        cout << "Input karakter baru ke-" << (i + 1) << ": ";
        cin >> x;
        insert(&q, x);
    }

    // 4. Menampilkan front dan rear
    cout << "\nPosisi index front dan rear:\n";
    cout << "Front = " << q.front << endl;
    cout << "Rear  = " << q.rear << endl;

    // 5. Tampilkan isi queue
    cout << "\nIsi queue terakhir:\n";
    display(&q);

    return 0;
}
