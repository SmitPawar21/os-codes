#include<stdio.h>
#include<limits.h>

#define SIZE 5

int AT[SIZE];
int BT[SIZE];
int CT[SIZE];
int TAT[SIZE];
int WT[SIZE];
int RT[SIZE];

int completed[SIZE];

void take_inputs() {
    int i;
    printf("Enter values for AT and BT for all processes:\n");
    for(i=0; i<SIZE; i++) {
        printf("AT = ");
        scanf("%d", &AT[i]);
        printf("BT = ");
        scanf("%d", &BT[i]);
    }

    for(i=0; i<SIZE; i++) {
        completed[i] = 0;
    }

    for(i=0; i<SIZE; i++) {
        RT[i] = BT[i];
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
    int i, index, min, check;

    while(allCompleted() == 0) {
        min = INT_MAX;
        check = 0;

        for(i=0; i<SIZE; i++) {
            if(completed[i] == 0 && AT[i] <= time && RT[i] < min) {
                min = RT[i];
                index = i;
                check = 1;
            }
        }

        if(check == 0) {
            time++;
            continue;
        }

        RT[index]--;
        if(RT[index] == 0) {
            CT[index] = time+1;
            completed[index] = 1;
        }        

        time++;
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

    printf("CT\t TAT\t WT");
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