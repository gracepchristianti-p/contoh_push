#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt, qt;
    int ct, tat, wt, rt;
    int queue;      // 1 = RR, 2 = FCFS
    int remaining;
    bool started = false;
};

int main() {
    int n;
    cout << "Jumlah proses: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Proses " << i + 1 << " (Name AT BT Queue): ";
        cin >> p[i].name >> p[i].at >> p[i].bt >> p[i].queue;
        p[i].remaining = p[i].bt;
        p[i].rt = -1;
    }

    queue<int> q1, q2;
    int time = 0, done = 0;
    int quantum = 2;
    vector<string> gantt;

    while (done < n) {

        // masuk proses yang datang
        for (int i = 0; i < n; i++) {
            if (p[i].at == time) {
                if (p[i].queue == 1) q1.push(i);
                else q2.push(i);
            }
        }

        int cur = -1;
        int level = 0;

        // Prioritas ke Queue 1 (Round Robin)
        if (!q1.empty()) {
            cur = q1.front();
            q1.pop();
            level = 1;
        }
        // Jika Q1 kosong, jalankan Q2 (FCFS)
        else if (!q2.empty()) {
            cur = q2.front();
            q2.pop();
            level = 2;
        }

        // CPU idle
        if (cur == -1) {
            gantt.push_back("Idle");
            time++;
            continue;
        }

        // response time
        if (!p[cur].started) {
            p[cur].started = true;
            p[cur].rt = time - p[cur].at;
        }

        // Eksekusi proses
        int slice = (level == 1 ? quantum : p[cur].remaining);

        for (int t = 0; t < slice; t++) {
            if (p[cur].remaining > 0) {
                gantt.push_back(p[cur].name + "(Q" + to_string(level) + ")");
                p[cur].remaining--;
                time++;

                // masukkan proses lain yang datang selama eksekusi
                for (int i = 0; i < n; i++) {
                    if (p[i].at == time) {
                        if (p[i].queue == 1) q1.push(i);
                        else q2.push(i);
                    }
                }
            }
            if (p[cur].remaining == 0) break;
        }

        // Jika selesai, hitung CT
        if (p[cur].remaining == 0) {
            p[cur].ct = time;
            done++;
        }
        else {
            // Masukkan kembali ke queue sesuai kelas
            if (level == 1) q1.push(cur);
            else q2.push(cur);
        }
    }

    // Hitung TAT, WT
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Tampilkan Gantt Chart
    cout << "\n=== GANTT CHART ===\n";
    for (int i = 0; i < gantt.size(); i++)
        cout << setw(5) << gantt[i];
    cout << endl;

    // Tabel Hasil
    cout << "\n=== TABEL HASIL ===\n";
    cout << "Name  AT  BT  Q  CT  TAT  WT  RT\n";
    for (auto &x : p) {
        cout << setw(4) << x.name
             << setw(4) << x.at
             << setw(4) << x.bt
             << setw(4) << x.queue
             << setw(4) << x.ct
             << setw(5) << x.tat
             << setw(5) << x.wt
             << setw(5) << x.rt << endl;
    }

    // Rata-rata per queue
    double tat1=0, tat2=0, wt1=0, wt2=0;
    int c1=0, c2=0;

    for (auto &x : p) {
        if (x.queue == 1) {
            tat1 += x.tat; wt1 += x.wt; c1++;
        } else {
            tat2 += x.tat; wt2 += x.wt; c2++;
        }
    }

    cout << "\n=== RATA-RATA PER QUEUE ===\n";
    cout << "Queue 1 (RR):  WT=" << wt1/c1 << "   TAT=" << tat1/c1 << endl;
    cout << "Queue 2 (FCFS): WT=" << wt2/c2 << "   TAT=" << tat2/c2 << endl;

    return 0;
}
