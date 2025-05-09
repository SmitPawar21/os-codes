#include<stdio.h>
#include<limits.h>

#define SIZE 5

int AT[SIZE];
int BT[SIZE];
int CT[SIZE];
int TAT[SIZE];
int WT[SIZE];

int completed[SIZE];

void take_inputs() {
    int i;

    printf("Enter the values for AT and BT for all processes:\n");
    for(i=0; i<SIZE; i++) {
        printf("Process %d:\n", i+1);
        printf("AT = ");
        scanf("%d", &AT[i]);
        printf("BT = ");
        scanf("%d", &BT[i]);
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
    int i, min, check, index;

    while(allCompleted() == 0) {
        min = INT_MAX;
        check = 0;
        for(i=0; i<SIZE; i++) {
            if(completed[i] == 0 && AT[i] <= time && BT[i] < min) {
                min = BT[i];
                index = i;
                check = 1;
            }
        }

        if(check == 0) {
            time++;
            continue;
        }

        CT[index] = time + BT[index];
        completed[index] = 1;
        time = time + BT[index];
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