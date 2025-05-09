#include<stdio.h>
#define SIZE 5

int AT[SIZE];
int BT[SIZE];
int CT[SIZE];
int TAT[SIZE];
int WT[SIZE];
int ordered_processes[SIZE];

void calculate_CT() {
    // sort according to the arrival time
    int arr[SIZE];
    int i, j, temp;

    for(i=0; i<SIZE; i++) {
        arr[i] = AT[i];
    }

    for(i=0; i<SIZE; i++) {
        ordered_processes[i] = i;
    }

    for(i=0; i<SIZE; i++) {
        for(j=i+1; j<SIZE; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;

                temp = ordered_processes[j];
                ordered_processes[j] = ordered_processes[i];
                ordered_processes[i] = temp;
            }
        }
    }

    CT[ordered_processes[0]] = AT[ordered_processes[0]] + BT[ordered_processes[0]];
    for(i=1; i<SIZE; i++) {
        if(AT[ordered_processes[i]] > CT[ordered_processes[i-1]]) {
            CT[ordered_processes[i]] = AT[ordered_processes[i]] + BT[ordered_processes[i]];
        } else {
            CT[ordered_processes[i]] = CT[ordered_processes[i-1]] + BT[ordered_processes[i]];
        }
    }
}

void calculate_TAT() {
    int i;

    for(i=0; i<SIZE; i++) {
        TAT[i] = CT[i] - AT[i];
    }
}

void calculate_WT() {
    int i;

    for(i=0; i<SIZE; i++) {
        WT[i] = TAT[i] - BT[i];
    }
}

void display_gantt_chart() {
    int i;
    int current_time = 0;

    printf("\nGantt Chart:\n");

    for(i = 0; i < SIZE; i++) {
        int p = ordered_processes[i];

        if(AT[p] > current_time) {
            printf("| Idle ");
            current_time = AT[p];
        }

        printf("| P%d ", p + 1);
        current_time += BT[p];
    }
    printf("|\n");

    current_time = 0;
    printf("0");

    for(i = 0; i < SIZE; i++) {
        int p = ordered_processes[i];

        if(AT[p] > current_time) {
            printf("    %d", AT[p]);
            current_time = AT[p];
        }

        current_time += BT[p];
        printf("    %d", current_time);
    }

    printf("\n");
}

void main() {
    int i;

    printf("Enter the values for Arrival Time and Burst Time for %d processes:\n", SIZE);
    for(i=0; i<SIZE; i++) {
        printf("Arrival Time for Process %d:", i+1);
        scanf("%d", &AT[i]);
        printf("Burst Time for Process %d:", i+1);
        scanf("%d", &BT[i]);
    }

    calculate_CT();
    calculate_TAT();
    calculate_WT();

    for(i=0; i<SIZE; i++) {
        printf("\nProcess %d: AT: %d BT: %d CT: %d TAT: %d WT:%d\n", i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    display_gantt_chart();
}