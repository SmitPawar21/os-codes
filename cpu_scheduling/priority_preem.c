#include <stdio.h>
#include <limits.h>
#define SIZE 5

int AT[SIZE]; 
int BT[SIZE];
int CT[SIZE];
int TAT[SIZE];
int WT[SIZE];
int P[SIZE];
int RT[SIZE];
int completed[SIZE];

int allCompleted() {
    int i;
    for(i=0; i<SIZE; i++) {
        if(completed[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void calculate_CT() {
    int i, min_P, check;
    int time = 0;
    int earliest = -1;

    for(i=0; i<SIZE; i++) {
        RT[i] = BT[i];
    }

    for(i=0; i<SIZE; i++) {
        completed[i] = 0;
    }

    while(allCompleted() == 0) {
        min_P = INT_MAX;
        check = 0;

        for(i=0; i<SIZE; i++) {
            if(completed[i]==0 && AT[i] <= time && P[i] < min_P) {
                min_P = P[i];
                earliest = i;
                check = 1;
            }
        }

        if(check == 0) {
            time++;
            continue;
        }

        RT[earliest]--;

        if(RT[earliest] == 0) {
            completed[earliest] = 1;
            CT[earliest] = time+1;
        }

        time++;
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

void main()
{
    int i;

    printf("Enter Arrival and Burst time for %d processes: ", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Arrival time = ");
        scanf("%d", &AT[i]);
        printf("Burst time = ");
        scanf("%d", &BT[i]);
        printf("Priority = ");
        scanf("%d", &P[i]);
    }

    calculate_CT();
    calculate_TAT();
    calculate_WT();

    for (i = 0; i < SIZE; i++)
    {
        printf("Process %d:\nAT: %d, BT: %d, Priority: %d, CT: %d, TAT: %d, WT: %d\n", i + 1, AT[i], BT[i], P[i], CT[i], TAT[i], WT[i]);
    }
}