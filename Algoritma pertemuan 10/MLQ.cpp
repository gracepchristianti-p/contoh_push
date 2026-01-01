#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt, rem, ct, tat, wt, rt;
    int qlevel;
    bool started = false;
};

int main() {
    int n;
    cout << "Jumlah proses: ";
    cin >> n;

    int quantum;
    cout << "Masukkan quantum Round Robin: ";
    cin >> quantum;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNama proses : ";
        cin >> p[i].name;
        cout << "Arrival Time : ";
        cin >> p[i].at;
        cout << "Burst Time : ";
        cin >> p[i].bt;
        p[i].rem = p[i].bt;
        cout << "Queue (1=RR,2=FCFS): ";
        cin >> p[i].qlevel;
        p[i].rt = -1;
    }

    queue<int> q1; // Round Robin
    queue<int> q2; // FCFS
    int time = 0;
    int done = 0;

    vector<string> gantt;
    vector<int> ganttStart;

    while (done < n) {

        // Masukkan proses yang datang pada waktu saat ini
        for (int i = 0; i < n; i++) {
            if (p[i].at == time) {
                if (p[i].qlevel == 1) q1.push(i);
                else q2.push(i);
            }
        }

        int current = -1;
        int slot = 0;

        // Queue 1 (RR)
        if (!q1.empty()) {
            current = q1.front();
            q1.pop();
            slot = min(quantum, p[current].rem);
        }
        // Queue 2 (FCFS)
        else if (!q2.empty()) {
            current = q2.front();
            q2.pop();
            slot = p[current].rem;
        }
        else {
            time++; // idle
            continue;
        }

        // Gantt Chart
        gantt.push_back(p[current].name + "(Q" + to_string(p[current].qlevel) + ")");
        ganttStart.push_back(time);

        // Eksekusi
        for (int t = 0; t < slot; t++) {
            if (p[current].rt == -1)
                p[current].rt = time - p[current].at;

            p[current].rem--;
            time++;

            // Cek proses baru datang
            for (int i = 0; i < n; i++) {
                if (p[i].at == time) {
                    if (p[i].qlevel == 1) q1.push(i);
                    else q2.push(i);
                }
            }

            if (p[current].rem == 0) break;
        }

        if (p[current].rem == 0) {
            p[current].ct = time;
            p[current].tat = p[current].ct - p[current].at;
            p[current].wt = p[current].tat - p[current].bt;
            done++;
        }
        else {
            if (p[current].qlevel == 1) q1.push(current);
            else q2.push(current);
        }
    }

    // ==================== OUTPUT =====================

    cout << "\nQuantum yang digunakan (RR): " << quantum << "\n"; // <-- tambahan

    cout << "\n\n=== GANTT CHART (MLQ) ===\n";
    for (int i = 0; i < gantt.size(); i++) {
        cout << "[" << ganttStart[i] << "]--" << gantt[i] << "--";
    }
    cout << "[" << time << "]\n";

    cout << "\n=== TABEL HASIL ===\n";
    cout << left << setw(10) << "Proses"
        << setw(10) << "AT"
        << setw(10) << "BT"
        << setw(10) << "Q"
        << setw(10) << "CT"
        << setw(10) << "TAT"
        << setw(10) << "WT"
        << setw(10) << "RT"
        << "\n";

    double avgWT1=0, avgTAT1=0, count1=0;
    double avgWT2=0, avgTAT2=0, count2=0;

    for (auto &x : p) {
        cout << left << setw(10) << x.name
            << setw(10) << x.at
            << setw(10) << x.bt
            << setw(10) << x.qlevel
            << setw(10) << x.ct
            << setw(10) << x.tat
            << setw(10) << x.wt
            << setw(10) << x.rt
            << "\n";

        if (x.qlevel == 1) {
            avgWT1 += x.wt; avgTAT1 += x.tat; count1++;
        } else {
            avgWT2 += x.wt; avgTAT2 += x.tat; count2++;
        }
    }

    cout << "\n=== RATA-RATA PER QUEUE ===\n";
    if (count1 > 0)
        cout << "Queue 1 (RR): Avg WT = " << avgWT1/count1
            << ", Avg TAT = " << avgTAT1/count1 << "\n";
    if (count2 > 0)
        cout << "Queue 2 (FCFS): Avg WT = " << avgWT2/count2
            << ", Avg TAT = " << avgTAT2/count2 << "\n";

    return 0;
}