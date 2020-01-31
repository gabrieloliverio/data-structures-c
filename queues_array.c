#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void enqueue(int value);
int dequeue();
int peek();
void display();
int front = -1, rear = -1;
int queue[MAX];

int main() {
    int option;
    int value;

    do
    {
        system("clear");
        printf("\n******************************************************************");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\n>>> ");
        scanf("%d", &option);
        system("clear");

        switch (option)
        {
        case 1:
            system("clear");
            printf("Enter the value: ");
            scanf("%d", &value);

            enqueue(value);
            break;
        case 2:
            system("clear");
            value = dequeue();

            if (value != -1)
            {
                printf("Deleted value: %d", value);
            }

            getchar();
            getchar();
            break;
        case 3:
            value = peek();
            if (value != -1)
            {
                printf("%d", value);
            }

            getchar();
            getchar();
            break;
        case 4:
            system("clear");
            display();
            getchar();
            getchar();
            break;
        default:
            break;
        }
    } while (option != 5);
}

void enqueue(int value) 
{
    if (rear == MAX - 1) {
        printf("OVERFLOW");
        return;
    }

    if (rear == -1 && front == -1) {
        rear = front = 0;
    }

    queue[rear] = value;
    rear++;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("UNDERFLOW");
    }

    front++;
}

int peek() {
    if (front == -1 || front > rear) {
        printf("EMPTY QUEUE");
        return -1;
    }
    
    return queue[front];
}

void display() {
    if ((front == -1 && rear == -1) || front >= rear) {
        printf("EMPTY QUEUE");
        return;
    }

    printf("FRONT => ");
    for (int i = front; i < rear; i++) {
        printf("%d\t", queue[i]);
    }
    printf(" <= REAR");
}