// this code is still in progress. not completed

#include<stdio.h>
#include<limits.h>

#define PAGES 21
#define FRAMES 3

int pages[PAGES];
int curr_frame[FRAMES];
int ages[FRAMES];

int page_hits = 0;
int page_faults = FRAMES;

void take_inputs() {
    int i;

    printf("Enter the values for page sin sequence: \n");
    for(i=0; i<PAGES; i++) {
        scanf("%d", &pages[i]);
    }

    for(i=0; i<FRAMES; i++) {
        curr_frame[i] = pages[i];
    }
}

void calculate_PHPF() {
    int i, j, key, max, index;
    int future_vals[FRAMES];

    for(i=FRAMES; i<PAGES; i++) {
        key = pages[i];

        if(isPresent(key) == 1) {
            page_hits++;
        }

        else {
            for(j=1+1; j<PAGES; j++) {
                future_vals = {PAGES+1};
                max = PAGES+1;

                if(isPresent(j) == 1) {
                    
                }
            }
        }
    }
}

void main() {
    take_inputs();
    calculate_PHPF();
    print_all();
}