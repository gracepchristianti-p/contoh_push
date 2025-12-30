#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt, remaining, queueLevel;
    int ct, tat, wt, rt;
    bool started;
};

int main() {
    int n;
    cout << "=== MULTI-LEVEL QUEUE SCHEDULING ===" << endl;
    cout << "Masukkan jumlah proses: ";
    cin >> n;
    
    vector<Process> p(n);
    
    for(int i = 0; i < n; i++) {
        cout << "\nProses " << (i+1) << ":" << endl;
        cout << "Nama: "; cin >> p[i].name;
        cout << "AT: "; cin >> p[i].at;
        cout << "BT: "; cin >> p[i].bt;
        cout << "Queue (1=RR, 2=FCFS): "; cin >> p[i].queueLevel;
        p[i].remaining = p[i].bt;
        p[i].started = false;
    }
    
    queue<int> q1, q2;
    vector<bool> inQueue(n, false);
    vector<string> gantt;
    vector<int> ganttTime;
    int currentTime = 0, completed = 0;
    
    ganttTime.push_back(0);
    
    while(completed < n) {
        // Masukkan proses yang sudah arrive
        for(int i = 0; i < n; i++) {
            if(p[i].at <= currentTime && !inQueue[i] && p[i].remaining > 0) {
                if(p[i].queueLevel == 1) q1.push(i);
                else q2.push(i);
                inQueue[i] = true;
            }
        }
        
        int idx = -1;
        
        // Prioritas Queue 1
        if(!q1.empty()) {
            idx = q1.front();
            q1.pop();
        } else if(!q2.empty()) {
            idx = q2.front();
            q2.pop();
        }
        
        if(idx == -1) {
            currentTime++;
            continue;
        }
        
        // Response Time
        if(!p[idx].started) {
            p[idx].rt = currentTime - p[idx].at;
            p[idx].started = true;
        }
        
        // Eksekusi
        int execTime;
        if(p[idx].queueLevel == 1) {
            execTime = min(2, p[idx].remaining); // Quantum = 2
        } else {
            execTime = p[idx].remaining; // FCFS sampai selesai
        }
        
        p[idx].remaining -= execTime;
        currentTime += execTime;
        
        gantt.push_back(p[idx].name);
        ganttTime.push_back(currentTime);
        
        // Masukkan proses baru yang arrive
        for(int i = 0; i < n; i++) {
            if(p[i].at <= currentTime && !inQueue[i] && p[i].remaining > 0) {
                if(p[i].queueLevel == 1) q1.push(i);
                else q2.push(i);
                inQueue[i] = true;
            }
        }
        
        if(p[idx].remaining == 0) {
            completed++;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        } else if(p[idx].queueLevel == 1) {
            q1.push(idx); // RR kembali ke queue
        }
    }
    
    // Gantt Chart
    cout << "\n=== GANTT CHART ===" << endl;
    cout << "|";
    for(auto g : gantt) cout << " " << g << " |";
    cout << endl;
    
    cout << "0";
    for(int i = 1; i < ganttTime.size(); i++) {
        cout << setw(4) << ganttTime[i];
    }
    cout << endl;
    
    // Tabel
    cout << "\n=== TABEL HASIL ===" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "| Proses | Queue | AT | BT | CT | TAT | WT | RT |" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    float totalTAT = 0, totalWT = 0, totalRT = 0;
    float tatQ1 = 0, wtQ1 = 0, tatQ2 = 0, wtQ2 = 0;
    int cntQ1 = 0, cntQ2 = 0;
    
    for(int i = 0; i < n; i++) {
        cout << "| " << setw(6) << left << p[i].name 
             << " |   Q" << p[i].queueLevel << "  "
             << "| " << setw(2) << p[i].at
             << " | " << setw(2) << p[i].bt
             << " | " << setw(2) << p[i].ct
             << " | " << setw(3) << p[i].tat
             << " | " << setw(2) << p[i].wt
             << " | " << setw(2) << p[i].rt << " |" << endl;
        
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
        totalRT += p[i].rt;
        
        if(p[i].queueLevel == 1) {
            tatQ1 += p[i].tat; wtQ1 += p[i].wt; cntQ1++;
        } else {
            tatQ2 += p[i].tat; wtQ2 += p[i].wt; cntQ2++;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
    
    // Statistik
    cout << "\n=== STATISTIK ===" << endl;
    cout << fixed << setprecision(2);
    cout << "Rata-rata TAT: " << totalTAT/n << endl;
    cout << "Rata-rata WT : " << totalWT/n << endl;
    cout << "Rata-rata RT : " << totalRT/n << endl;
    
    cout << "\n=== PERBANDINGAN QUEUE ===" << endl;
    if(cntQ1 > 0) {
        cout << "Queue 1 (RR) - Avg TAT: " << tatQ1/cntQ1 
             << ", Avg WT: " << wtQ1/cntQ1 << endl;
    }
    if(cntQ2 > 0) {
        cout << "Queue 2 (FCFS) - Avg TAT: " << tatQ2/cntQ2 
             << ", Avg WT: " << wtQ2/cntQ2 << endl;
    }
    
    cout << "\n=== ANALISIS MLQ ===" << endl;
    cout << "Kelebihan:" << endl;
    cout << "- Proses prioritas tinggi (Q1) mendapat CPU lebih cepat" << endl;
    cout << "- Queue 1 responsif untuk proses interaktif" << endl;
    cout << "\nKelemahan:" << endl;
    cout << "- Queue 2 bisa mengalami starvation" << endl;
    cout << "- Tidak ada perpindahan antar queue" << endl;
    
    return 0;
}