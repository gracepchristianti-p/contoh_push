#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at;           // Arrival Time
    int bt;           // Burst Time
    int remaining;    // Remaining Time
    int ct;           // Completion Time
    int tat;          // Turnaround Time
    int wt;           // Waiting Time
    int rt;           // Response Time
    bool started;     // Sudah pernah dijalankan?
};

int main() {
    int n;
    cout << "=== ALGORITMA SRTF (Shortest Remaining Time First) ===" << endl;
    cout << "\nMasukkan jumlah proses: ";
    cin >> n;
    
    vector<Process> p(n);
    
    // Input data proses
    for(int i = 0; i < n; i++) {
        cout << "\n--- Proses " << (i+1) << " ---" << endl;
        cout << "Nama proses: ";
        cin >> p[i].name;
        cout << "Arrival Time: ";
        cin >> p[i].at;
        cout << "Burst Time: ";
        cin >> p[i].bt;
        
        p[i].remaining = p[i].bt;
        p[i].started = false;
        p[i].rt = -1;
    }
    
    // Variabel untuk scheduling
    int currentTime = 0;
    int completed = 0;
    int preemptionCount = 0;
    int lastProcess = -1;
    
    // Gantt Chart
    vector<pair<string, int>> gantt;
    
    cout << "\n=== PROSES SCHEDULING ===" << endl;
    
    while(completed < n) {
        int shortest = -1;
        int minRemaining = INT_MAX;
        
        // Cari proses dengan remaining time terpendek yang sudah arrive
        for(int i = 0; i < n; i++) {
            if(p[i].at <= currentTime && p[i].remaining > 0) {
                if(p[i].remaining < minRemaining) {
                    minRemaining = p[i].remaining;
                    shortest = i;
                }
                // Jika sama, pilih yang arrival time lebih awal
                else if(p[i].remaining == minRemaining && p[i].at < p[shortest].at) {
                    shortest = i;
                }
            }
        }
        
        if(shortest == -1) {
            // Tidak ada proses yang ready, CPU idle
            currentTime++;
            continue;
        }
        
        // Response Time (pertama kali dijalankan)
        if(!p[shortest].started) {
            p[shortest].rt = currentTime - p[shortest].at;
            p[shortest].started = true;
        }
        
        // Deteksi preemption
        if(lastProcess != -1 && lastProcess != shortest && p[lastProcess].remaining > 0) {
            preemptionCount++;
            cout << "⚡ Preemption terjadi! " << p[lastProcess].name 
                 << " → " << p[shortest].name << " pada waktu " << currentTime << endl;
        }
        
        // Eksekusi proses selama 1 unit waktu
        p[shortest].remaining--;
        currentTime++;
        
        // Tambahkan ke Gantt Chart
        if(gantt.empty() || gantt.back().first != p[shortest].name) {
            gantt.push_back({p[shortest].name, currentTime});
        } else {
            gantt.back().second = currentTime;
        }
        
        // Cek apakah proses selesai
        if(p[shortest].remaining == 0) {
            completed++;
            p[shortest].ct = currentTime;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            cout << "✓ " << p[shortest].name << " selesai pada waktu " << currentTime << endl;
        }
        
        lastProcess = shortest;
    }
    
    // Tampilkan Gantt Chart
    cout << "\n=== GANTT CHART ===" << endl;
    cout << "|";
    for(auto g : gantt) {
        cout << " " << g.first << " |";
    }
    cout << endl;
    
    cout << "0";
    for(auto g : gantt) {
        cout << setw(4) << g.second;
    }
    cout << endl;
    
    // Tampilkan tabel hasil
    cout << "\n=== TABEL HASIL ===" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "| Proses |  AT |  BT |  CT | TAT |  WT |  RT |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    float totalTAT = 0, totalWT = 0, totalRT = 0;
    
    for(int i = 0; i < n; i++) {
        cout << "| " << setw(6) << left << p[i].name 
             << " | " << setw(3) << p[i].at
             << " | " << setw(3) << p[i].bt
             << " | " << setw(3) << p[i].ct
             << " | " << setw(3) << p[i].tat
             << " | " << setw(3) << p[i].wt
             << " | " << setw(3) << p[i].rt << " |" << endl;
        
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
        totalRT += p[i].rt;
    }
    
    cout << "----------------------------------------------------------------" << endl;
    
    // Rata-rata
    cout << "\n=== STATISTIK ===" << endl;
    cout << "Rata-rata Turnaround Time: " << fixed << setprecision(2) << totalTAT/n << endl;
    cout << "Rata-rata Waiting Time   : " << totalWT/n << endl;
    cout << "Rata-rata Response Time  : " << totalRT/n << endl;
    cout << "Jumlah Preemption        : " << preemptionCount << endl;
    
    // Analisis starvation
    cout << "\n=== ANALISIS ===" << endl;
    bool starvationFound = false;
    for(int i = 0; i < n; i++) {
        if(p[i].wt > p[i].bt * 2) {
            cout << "⚠ " << p[i].name << " mengalami waiting time tinggi (" 
                 << p[i].wt << " unit), kemungkinan starvation!" << endl;
            starvationFound = true;
        }
    }
    
    if(!starvationFound) {
        cout << "✓ Tidak ada indikasi starvation yang signifikan." << endl;
    }
    
    cout << "\nCatatan: SRTF adalah algoritma preemptive yang selalu memilih" << endl;
    cout << "proses dengan sisa waktu terpendek. Proses dengan burst time" << endl;
    cout << "panjang dapat mengalami starvation jika terus ada proses baru" << endl;
    cout << "dengan burst time lebih pendek yang datang." << endl;
    
    return 0;
}