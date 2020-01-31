#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX], top=-1;
void push(int stack[], int value);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);

int main() {
    int option;
    int value;

    do
    {
        system("clear");
        printf("\n******************************************************************");
        printf("\n1. Push");
        printf("\n2. Pop");
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

            push(stack, value);
            break;
        case 2:
            system("clear");
            value = pop(stack);

            if (value != -1) {
                printf("Popped value: %d", value);
            }

            getchar();
            getchar();
            break;
        case 3:
            value = peek(stack);
            if (value != -1) 
            {
                printf("%d", value);
            }

            getchar();
            getchar();
            break;
        case 4:
            system("clear");
            display(stack);
            getchar();
            getchar();
            break;
        default:
            break;
        }
    } while (option != 5);
}

void push(int stack[], int value)
{
    if (top == MAX - 1)
    {
        system("clear");
        printf("OVERFLOW...");
    }

    top++;
    stack[top] = value;
}

int pop(int stack[])
{
    int value;

    if (top == -1)
    {
        system("clear");
        printf("UNDERFLOW...");
        return -1;
    }

    value = stack[top];
    top--;

    return value;
}

int peek(int stack[]) 
{
    if (top == -1) {
        printf("EMPTY STACK");
        return -1;
    }
    return stack[top];
}

void display(int stack[])
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
}