#include <iostream>
using namespace std;

// Struktur data pelanggan
struct Pelanggan {
    int nomor;
    int lamaPelayanan;
    Pelanggan *next;
};

// Struktur Queue
struct Queue {
    Pelanggan *front;
    Pelanggan *rear;
    int count;
};

// Inisialisasi queue
void init(Queue *q) {
    q->front = q->rear = NULL;
    q->count = 0;
}

// Cek queue kosong
bool isEmpty(Queue *q) {
    return q->front == NULL;
}

// Tambah pelanggan (enqueue)
void enqueue(Queue *q, int nomor, int pelayanan) {
    Pelanggan *baru = new Pelanggan;
    baru->nomor = nomor;
    baru->lamaPelayanan = pelayanan;
    baru->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }

    q->count++;
    cout << "Pelanggan nomor " << nomor << " masuk antrian.\n";
}

// Layani pelanggan (dequeue)
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }

    Pelanggan *hapus = q->front;
    cout << "Melayani pelanggan nomor " << hapus->nomor 
         << " (Waktu pelayanan: " << hapus->lamaPelayanan 
         << " detik)\n";

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    delete hapus;
    q->count--;
}

// Tampilkan antrian
void display(Queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "\nPelanggan yang sedang menunggu:\n";
    Pelanggan *temp = q->front;

    while (temp != NULL) {
        cout << "Nomor Antrian: " << temp->nomor
             << ", Lama Pelayanan: " << temp->lamaPelayanan << " detik\n";
        temp = temp->next;
    }
}

// Tampilkan jumlah pelanggan
void jumlahPelanggan(Queue *q) {
    cout << "Jumlah pelanggan dalam antrian: " << q->count << endl;
}

int main() {
    Queue q;
    init(&q);

    int pilihan;
    int nomor = 1;  // nomor antrian otomatis

    do {
        cout << "\n=== SIMULASI ANTRIAN KASIR ===\n";
        cout << "1. Tambah Pelanggan\n";
        cout << "2. Layani Pelanggan\n";
        cout << "3. Tampilkan Pelanggan Menunggu\n";
        cout << "4. Tampilkan Jumlah Pelanggan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            int waktu;
            cout << "Masukkan lama pelayanan (detik): ";
            cin >> waktu;
            enqueue(&q, nomor++, waktu);
            break;
        }
        case 2:
            dequeue(&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            jumlahPelanggan(&q);
            break;

        case 5:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);

    return 0;
}
