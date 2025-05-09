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

    printf("Enter the values for pages in sequence:\n");
    for(i=0; i<PAGES; i++) {
        scanf("%d", &pages[i]);
    }

    for(i=0; i<FRAMES; i++) {
        curr_frame[i] = pages[i];
        ages[i] = 1;
    }
}

int isPresent(int key) {
    int i;

    for(i=0; i<FRAMES; i++) {
        if(curr_frame[i] == key) {
            ages[i]++;
            return 1;
        }
    }

    return 0;
}

void calculate_PHPF() {
    int i, j, key, index, min;

    for(i=FRAMES; i<PAGES; i++) {
        key = pages[i];

        if(isPresent(key) == 1) {
            page_hits++;
        }

        else {
            min = INT_MAX;
            for(j=0; j<FRAMES; j++) {
                if(ages[j] < min) {
                    min = ages[j];
                    index = j;
                }
            }

            curr_frame[index] = key;
            ages[index] = 1;
            page_faults++;
        }
    }
}

void print_all() {
    printf("Page Hits = %d\n", page_hits);
    printf("Page Faults = %d", page_faults);
}

void main() {
    take_inputs();
    calculate_PHPF();
    print_all();
}