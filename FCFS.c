#include<stdio.h>

#define SIZE 5

int process_no[SIZE];
int AT[SIZE];
int BT[SIZE];
int CT[SIZE];
int TAT[SIZE];
int WT[SIZE];
int ordered_processes[SIZE];

void calculate_CT () {
    int arr[SIZE];
    int i, j, sum, temp;

    for(i=0; i<SIZE; i++) {
        arr[i] = AT[i];
    }

    for(i=0; i<SIZE; i++) {
        ordered_processes[i] = i;
    }

    // Sorting according to Arrival Time
    for(i=0; i<SIZE; i++) {
        for(j=i+1; j<SIZE; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                temp = ordered_processes[i];
                ordered_processes[i] = ordered_processes[j];
                ordered_processes[j] = temp;
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
 
void main() {
    int i;
    printf("Enter input values for %d processes:\n", SIZE);

    for(i=0; i<SIZE; i++) {
        printf("Values for P%d :\n",i+1);

        printf("AT: ");
        scanf("%d", &AT[i]);

        printf("BT: ");
        scanf("%d", &BT[i]);
    }

    calculate_CT();
    calculate_TAT();
    calculate_WT();

    printf("P: \t AT \t BT \t CT \t TAT \t WT\n");
    for(i=0; i<SIZE; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n", i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
}
