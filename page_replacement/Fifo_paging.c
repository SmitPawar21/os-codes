#include<stdio.h>
#include<limits.h>

#define PAGES 21
#define FRAMES 3

int pages[PAGES];
int curr_frame[FRAMES];
int ages[FRAMES];

int page_faults = FRAMES;
int page_hits = 0;

void take_inputs() {
    int i;

    printf("Enter the values for all the pages in a sequence:");
    for(i=0; i<PAGES; i++) {
        scanf("%d", &pages[i]);
    }

    for(i=0; i<FRAMES; i++) {
        curr_frame[i] = pages[i];
        ages[i] = 1;
    }
}

int isPresent_in_frame(int key) {
    int i;
    for(i=0; i<FRAMES; i++) {
        if(curr_frame[i] == key) {
            return 1;
        }
    }

    return 0;
}

void calculate_PHPF() {
    int i, j, key;
    int max = INT_MIN;
    int index;

    for(i=FRAMES; i<PAGES; i++) {
        key = pages[i];
        
        if(isPresent_in_frame(key) == 1) {
            page_hits++;
        }

        else {
            for(j=0; j<FRAMES; j++) {
                if(ages[j] > max) {
                    max = ages[j];
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
    printf("Page Hits = %d", page_hits);
    printf("\nPage Faults = %d\n", page_faults);

    printf("Hit Ratio = %d/%d = %f\n", page_hits, PAGES, (float)page_hits/PAGES);
    printf("Miss Ratio = %d/%d = %f\n", page_faults, PAGES, (float)page_faults/PAGES);
}

void main() {
    take_inputs();
    calculate_PHPF();
    print_all();
}