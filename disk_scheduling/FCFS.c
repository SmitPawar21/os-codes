#include<stdio.h>
#include<stdlib.h>
#define SIZE 7

int sequence[SIZE];

int start_index = 50;
int end_index = 199;

int seek_time;

void take_inputs() {
    int i;

    printf("Enter the values for sequences:\n");
    for(i=0; i<SIZE; i++) {
        scanf("%d", &sequence[i]);
    }
}

void calculate_seektime() {
    int i, a, b;
    seek_time = abs(sequence[0] - start_index);
    for(i=1; i<SIZE; i++) {
        a = sequence[i-1];
        b = sequence[i];

        seek_time = seek_time + abs(b-a);
    }
    printf("SEEK TIME = %d\n", seek_time);
}

void display_track_movements() {
    int i;

    printf("TRACK MOVEMENTS:\n%d -> ", start_index);
    for(i=0; i<SIZE-1; i++) {
        printf("%d -> ", sequence[i]);
    }
    printf("%d\n", sequence[SIZE-1]);
}

void main() {
    take_inputs();
    calculate_seektime();
    display_track_movements();
}