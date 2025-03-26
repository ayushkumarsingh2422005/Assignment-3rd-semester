#include <iostream>
using namespace std;

// algo to implement first come first server scheduling algorithm
void fcfs(int n, int bt[], int at[]) {
    int wt[n], tat[n], ct[n];
    wt[0] = 0;
    ct[0] = bt[0];
    tat[0] = ct[0] - at[0];
    for (int i = 1; i < n; i++) {
        wt[i] = ct[i - 1] - at[i];
        ct[i] = ct[i - 1] + bt[i];
        tat[i] = ct[i] - at[i];
    }
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }
}

// main function
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], at[n];
    cout << "Enter the burst time and arrival time of each process: ";
    for (int i = 0; i < n; i++) {
        cin >> bt[i] >> at[i];
    }
    fcfs(n, bt, at);
    return 0;
}