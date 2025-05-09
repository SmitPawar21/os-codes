#include<stdio.h>
#include<limits.h>
#define BLOCKS 5
#define SIZE 6

int processes[SIZE];
int memory_blocks[BLOCKS];
int answer[SIZE];
int completed[BLOCKS];

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
    int i, j;

    for(i=0; i<SIZE; i++) {
        int size = processes[i];
        int i_fragmentation = INT_MIN;
        int block = -1;

        for(j=0; j<BLOCKS; j++) {
            int diff = memory_blocks[j] - size;

            if(completed[j] == 0 && (diff > 0)) {
                if(diff > i_fragmentation) {
                    i_fragmentation = diff;
                    block = j;
                }
            }
        }

        if(block == -1) {
            answer[i] = -1;
        } else {
            answer[i] = block+1;
            completed[block] = 1;
        }
    }
}

void print_outputs() {
    int i; 

    printf("\nOUTPUT\n");
    for(i=0; i<SIZE; i++) {
        printf("Process no. = %d, Process size = %d, Block allotted = %d\n", i+1, processes[i], answer[i]);
    }
}

void main() {
    take_inputs();
    allot_blocks();
    print_outputs();
}