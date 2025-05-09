#include<stdio.h>

#define SIZE 7

int sequence[SIZE];
int left[SIZE];
int right[SIZE];

int start = 50;
int end = 200;

void take_inputs() {
    int i, j, k=0, x=0, temp, min, max;

    printf("Enter the values for sequence:\n");
    for(i=0; i<SIZE; i++) {
        scanf("%d", &sequence[i]);
    }

    for(i=0; i<SIZE; i++) {
        if(sequence[i] < start) {
            left[x++] = sequence[i];
        } else {
            right[k++] = sequence[i];
        }
    }

    for(i=0; i<k; i++) {
        min = i;
        for(j=i; j<x; j++) {
            if(right[j] < right[min]) {
                min = j;
            }
        }

        temp = right[i];
        right[i] = right[min];
        right[min] = temp;
    }

    for(i=0; i<x; i++) {
        max = i;
        for(j=i; j<x; j++) {
            if(left[i] > left[max]) {
                max = j;
            }
        }

        temp = left[i];
        left[i] = left[max];
        left[max] = temp;
    }

    printf("Track movements:\n%d -> ", start);
    for(i=0; i<k; i++) {
        printf("%d -> ", right[i]);
    }

    for(i=0; i<x-1; i++) {
        printf("%d -> ", left[i]);
    }
    printf("%d", left[x-1]);
}

void main() {
    take_inputs();
}