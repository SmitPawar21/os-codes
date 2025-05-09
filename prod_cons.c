#include<stdio.h>

int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;

void prod() {
    if(mutex == 1 && empty != 0) {
        --mutex;
        ++full;
        --empty;
        x++;
        printf("producer produced %d\n", x);
        ++mutex;
    } else {
        printf("Buffer is full\n");
    }
}

void cons() {
    if(mutex == 1 && full != 0) {
        ++mutex;
        --full;
        ++empty;
        x--;
        printf("");
        --mutex;
    } else {
        printf("Buffer is empty\n");
    }
}

void main() {
    int choice, running = 1;
    while(running == 1) {
        printf("Enter the choice:\n1 for prod, 2 for cons, 3 for exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: prod();
                    break;
            case 2: cons();
                    break;
            case 3: running = 0;
                    break;
            default: printf("Enter valid choice\n");
        }
    }
}