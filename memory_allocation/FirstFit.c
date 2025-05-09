#include<stdio.h>
#define BLOCKS 5
#define SIZE 6 // no. of process 

int processes[SIZE];
int memory_blocks[BLOCKS];
int answer[SIZE];
int completed[SIZE];

void take_inputs() {
    int i;

    printf("Enter the values for %d memory blocks: \n", BLOCKS);
    for(i=0; i<BLOCKS; i++) {
        scanf("%d", &memory_blocks[i]);
    }

    printf("Enter the values of process sizes for %d processes: \n", SIZE);
    for(i=0; i<SIZE; i++) {
        scanf("%d", &processes[i]);
    }

    for(i=0; i<BLOCKS; i++) {
        completed[i] = 0;
    }
}

void allot_blocks() {
    int i, j, check;

    for(i=0; i<SIZE; i++) {
        int size = processes[i];
        check = 0; //false if block not allotted

        for(j=0; j<BLOCKS; j++) {
            if(completed[j] == 0 && (size <= memory_blocks[j])) {
                answer[i] = j+1;
                completed[j] = 1;
                check = 1; //allotted
                break;
            }
        }

        if(check == 0) {
            answer[i] = -1;
        }
    }
}

void print_output() {
    int i;

    printf("\nOUTPUT\n");
    for(i=0; i<SIZE; i++) {
        printf("Process No. = %d, Process Size = %d, Block allotted = %d\n", i+1, processes[i], answer[i]);
    }
}

void main() {
    take_inputs();
    allot_blocks();
    print_output();
}