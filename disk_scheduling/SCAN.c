#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 7

int sequence[SIZE];
int left[SIZE];
int right[SIZE];

int start = 50;
int end = 200;

void take_inputs() {
    int i, j, k=0, x=0, temp, min, max;

    printf("Enter the values in sequence:\n");
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

    printf("left array: ");
    for(i=0; i<x; i++) {
        printf("%d ", left[i]);
    }
    printf("\n");

    //right sort
    for(i=0; i<k; i++) {
        min = i;
        for(j=i; j<k; j++) {
            if(right[j] < right[min]) {
                min = j;
            }
        }
        temp = right[i];
        right[i] = right[min];
        right[min] = temp;
    }

    //left sort
    for(i=0; i<x; i++) {
        max = i;
        for(j=i; j<x; j++) {
            if(left[j] > left[max]) {
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
    printf("%d -> ", end-1);

    for(i=0; i<x-1; i++) {
        printf("%d -> ", left[i]);
    }
    printf("%d\n", left[x-1]);
}

void main() {
    take_inputs();
}