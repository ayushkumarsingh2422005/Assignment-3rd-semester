#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt; // Remaining time
};

void sortByArrivalTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].at > processes[j + 1].at) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int findShortestRemainingTime(struct Process processes[], int n, int currentTime, int completed[]) {
    int minRT = 999999;
    int shortest = -1;
    
    for (int i = 0; i < n; i++) {
        if (completed[i] == 0 && processes[i].at <= currentTime) {
            if (processes[i].rt < minRT) {
                minRT = processes[i].rt;
                shortest = i;
            }
        }
    }
    return shortest;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    int completed[n];
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].bt);
        processes[i].rt = processes[i].bt; // Initialize remaining time
        completed[i] = 0;
    }

    sortByArrivalTime(processes, n);
    
    int currentTime = 0;
    int completedProcesses = 0;
    int prev = -1;
    
    printf("\nProcess Execution Order:\n");
    
    while (completedProcesses < n) {
        int shortest = findShortestRemainingTime(processes, n, currentTime, completed);
        
        if (shortest == -1) {
            currentTime++;
            continue;
        }

        // If different process from previous, print process id
        if (prev != shortest) {
            printf("P%d ", processes[shortest].pid);
            prev = shortest;
        }

        processes[shortest].rt--; // Decrease remaining time by 1
        currentTime++;

        // If process completes
        if (processes[shortest].rt == 0) {
            processes[shortest].ct = currentTime;
            processes[shortest].tat = processes[shortest].ct - processes[shortest].at;
            processes[shortest].wt = processes[shortest].tat - processes[shortest].bt;
            
            total_tat += processes[shortest].tat;
            total_wt += processes[shortest].wt;
            
            completed[shortest] = 1;
            completedProcesses++;
            prev = -1; // Reset prev as current process completed
        }
    }
    
    printf("\n\nProcess Details:\n");
    for (int i = 0; i < n; i++) {
        struct Process temp = processes[i];
        printf("Process ID: %d, Arrival Time: %d, Burst Time: %d, Completion Time: %d, Turnaround Time: %d, Waiting Time: %d\n", 
               temp.pid, temp.at, temp.bt, temp.ct, temp.tat, temp.wt);
    }
    
    printf("\nAverage Turnaround Time: %.2f", total_tat/n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt/n);

    return 0;
}
