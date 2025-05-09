#include<stdio.h>

#define SIZE 5

int AT[SIZE];
int BT[SIZE];
int CT[SIZE];
int TAT[SIZE];
int WT[SIZE];
int RT[SIZE];
int completed[SIZE];

int TQ;

void take_inputs() {
    int i;

    printf("Enter the value for Time Quantum = ");
    scanf("%d", &TQ);

    printf("Enter the values for AT and BT for all processes:\n");
    for(i=0; i<SIZE; i++) {
        printf("Process %d:\n", i+1);
        printf("AT = ");
        scanf("%d", &AT[i]);
        printf("BT = ");
        scanf("%d", &BT[i]);
        RT[i] = BT[i];
    }

    for(i=0; i<SIZE; i++) {
        completed[i] = 0;
    }
}

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
    int time = 0;
    int i, check;

    while(allCompleted() == 0) {
        for(i=0; i<SIZE; i++) {
            if(completed[i] == 0 && AT[i] <= time) {
                if(RT[i] > TQ) {
                    RT[i] = RT[i] - TQ;
                    time = time + TQ;
                    check = 1;
                } else {
                    time = time + RT[i];
                    completed[i] = 1;
                    CT[i] = time;
                    check = 1;
                }
            }
        }

        if(check == 0) {
            time++;
            continue;
        }
    }
}

void calculate_TAT_WT() {
    int i;
    
    for(i=0; i<SIZE; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
}

void print_all() {
    int i;
    printf("CT\t TAT\t WT\n");
    for(i=0; i<SIZE; i++) {
        printf("%d\t %d\t %d\n", CT[i], TAT[i], WT[i]);
    }
}

void main() {
    take_inputs();
    calculate_CT();
    calculate_TAT_WT();
    print_all();
}