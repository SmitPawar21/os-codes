#include<stdio.h>

#define SIZE 5

int process_no[SIZE];
int AT[SIZE];
int BT[SIZE];
int CT[SIZE];
int TAT[SIZE];
int WT[SIZE];

void sortProcesses() {
    int arr[SIZE];
    int brr[SIZE];
    int i, j, temp;

    for(i=0; i<SIZE; i++) {
        arr[i] = AT[i];
    }
    for(i=0; i<SIZE; i++) {
        brr[i] = BT[i];
    }
    for(i=0; i<SIZE; i++) {
        process_no[i] = i;
    }

    for(i=0; i<SIZE-1; i++) {
        for(j=i+1; j<SIZE; j++) {
            if(arr[j] < arr[i] || (arr[j] == arr[i] && brr[j] < brr[i]) ) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                temp = brr[i];
                brr[i] = brr[j];
                brr[j] = temp;

                temp = process_no[i];
                process_no[i] = process_no[j];
                process_no[j] = temp;
            }
        }
    }
}

void calculate_CT() {
    int i;

    CT[process_no[0]] = AT[process_no[0]] + BT[process_no[0]];

    for(i=1; i<SIZE; i++) {
        if(AT[process_no[i]] > CT[process_no[i-1]]) {
            CT[process_no[i]] = AT[process_no[i]] + BT[process_no[i]];
        } else {
            CT[process_no[i]] = CT[process_no[i-1]] + BT[process_no[i]];
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

    sortProcesses();
    calculate_CT();
    calculate_TAT();
    calculate_WT();

    printf("P: \t AT \t BT \t CT \t TAT \t WT\n");
    for(i=0; i<SIZE; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n", i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
}