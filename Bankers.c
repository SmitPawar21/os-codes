#include <stdio.h>
#define PROCESSES 3
#define RESOURCES 3

int allocated[PROCESSES][RESOURCES];
int max_need[PROCESSES][RESOURCES];
int remaining_need[PROCESSES][RESOURCES];
int available[PROCESSES+1][RESOURCES];

int total_resources[RESOURCES];

int safe_sequence[PROCESSES];

void take_inputs() {
    int i, j;

    printf("Enter the total value for each Resources:\n");
    for(i=0; i<RESOURCES; i++) {
        scanf("%d", &total_resources[i]);
    }
    printf("Enter the values for Allocated Resourcess for each process:\n");
    for(i=0; i<PROCESSES; i++) {
        for(j=0; j<RESOURCES; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }
    printf("Enter Maximum need of the resources for each process:\n");    
    for(i=0; i<PROCESSES; i++) {
        for(j=0; j<RESOURCES; j++) {
            scanf("%d", &max_need[i][j]);
        }
    }
}

void calculate_remaining_need() {
    int i, j;

    for(i=0; i<PROCESSES; i++) {
        for(j=0; j<RESOURCES; j++) {
            remaining_need[i][j] = max_need[i][j] - allocated[i][j];
        }
    }
}

void generate_safe_sequence() {
    int i, j;
    int total_allocated_resources[RESOURCES];
    
    for(j=0; j<RESOURCES; j++) {
        total_allocated_resources[j] = 0;
        for(i=0; i<PROCESSES; i++) {
            total_allocated_resources[j] = total_allocated_resources[j] + allocated[i][j];
        }
    }

    for(j=0; j<RESOURCES; j++) {
        available[0][j] = total_resources[j] - total_allocated_resources[j];
    }

    int count = 0;
    int index = 0; // process no.
    int avail_index = 0;
    int completed_process[PROCESSES];
    int check;

    for(i=0; i<PROCESSES; i++) {
        completed_process[i] = 0;
    }

    while(count <= PROCESSES) {
        check = 1; // true if this process is allocated
        if(completed_process[index] == 1) {
            index = (index+1)%PROCESSES;
            continue;
        }
        for(i=0; i<RESOURCES; i++) {
            if((available[avail_index][i] < remaining_need[index][i])) {
                check = 0;
                break;
            }
        }

        if(check == 0) {
            index = (index+1)%PROCESSES;
            count++;
            continue;
        }

        if(check == 1) {
            safe_sequence[avail_index] = index+1;
            completed_process[index] = 1;
            
            avail_index++;
            for(i=0; i<RESOURCES; i++) {
                available[avail_index][i] = available[avail_index-1][i] + allocated[index][i];
            }

            index = (index+1)%PROCESSES;
            count = 0;
        }

        if(avail_index == PROCESSES) {
            break;
        }
    }

    if(count > PROCESSES) {
        printf("\n--!!DEADLOCK DETECTED!!--\n");
    }

    else {
        printf("\nSafe Sequence = ");
        for(i=0; i<PROCESSES-1; i++) {
            printf("P%d -> ", safe_sequence[i]);
        }
        printf("P%d\n\n", safe_sequence[PROCESSES-1]);
    }
}

void print_all() {
    int i, j;
    printf("remaining need matrix:\n");
    for(i=0; i<PROCESSES; i++) {
        for(j=0; j<RESOURCES; j++) {
            printf("%d ", remaining_need[i][j]);
        }
        printf("\n");
    }

    printf("available matrix:\n");
    for(i=0; i<PROCESSES+1; i++) {
        for(j=0; j<RESOURCES; j++) {
            printf("%d ", available[i][j]);
        }
        printf("\n");
    }
}

void main() {
    take_inputs();
    calculate_remaining_need();
    generate_safe_sequence();
    print_all();
}