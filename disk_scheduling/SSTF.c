#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 7

int sequence[SIZE];
int ordered_seq[SIZE + 1];
int visited[SIZE];

int start = 50;
int index = 0;

int seek_time;

void take_inputs()
{
    int i;

    printf("Enter the values for sequence: \n");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &sequence[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        visited[i] = 0;
    }

    ordered_seq[index] = start;
}

void calculate_seek_time()
{
    int i, a, b;

    seek_time = abs(start - ordered_seq[0]);
    for(i=1; i<=SIZE; i++) {
        a = ordered_seq[i-1];
        b = ordered_seq[i];

        seek_time = seek_time + abs(b-a);
    }

    printf("Seek Time = %d\n", seek_time);

}

int allCompleted() {
    int i;
    for(i=0; i<SIZE; i++) {
        if(visited[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void display_track_movements()
{
    int i, min, key, temp;

    while (allCompleted() == 0)
    {
        min = INT_MAX;
        key = -1;
        temp = -1;

        for (i = 0; i < SIZE; i++)
        {
            if (visited[i] == 0 && abs(ordered_seq[index] - sequence[i]) < min)
            {
                min = abs(ordered_seq[index] - sequence[i]);
                key = sequence[i];
                temp = i;
            }
        }

        index++;
        ordered_seq[index] = key;
        visited[temp] = 1;
    }

    for(i=0; i<SIZE; i++) {
        printf("%d -> ", ordered_seq[i]);
    }
    printf("%d\n", ordered_seq[SIZE]);
}

void main()
{
    take_inputs();
    display_track_movements();
    calculate_seek_time();
}