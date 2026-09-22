#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct stack
{
    int top;
    int arr[MAX];
} stack;
// Function declaration
void create(stack *s);
int isempty(stack *s);
int isfull(stack *s);
void push(stack *s, int X);
int pop(stack *s);
void display(stack *s);

int main()
{
    stack S;
    int choice, x, item;

    create(&S);

    while (1)
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. Create Empty Stack\n");
        printf("2. Check Stack Empty\n");
        printf("3. Check Stack Full\n");
        printf("4. Push\n");
        printf("5. Pop\n");
        printf("6.Display");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create(&S);
            printf("Empty stack created successfully.\n");
            break;

        case 2:
            if (isempty(&S))
                printf("Stack is Empty.\n");
            else
                printf("Stack is NOT Empty.\n");
            break;

        case 3:
            if (isfull(&S))
                printf("Stack is Full.\n");
            else
                printf("Stack is NOT Full.\n");
            break;

        case 4:
            printf("Enter element to push: ");
            scanf("%d", &x);
            push(&S, x);
            break;

        case 5:
            item = pop(&S);
            printf("Deleted Element = %d\n", item);
            break;

        case 6:
            display(&S);
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
// function defintion
// create stack
void create(stack *s)
{
    s->top = -1;
}
// check empty or not
int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// check full or not
int isfull(stack *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// push
void push(stack *s, int X)
{
    // check full or not
    if (s->top == MAX - 1)
    {
        printf("stack overflow");
        exit(1);
    }
    s->top++;
    s->arr[s->top] = X;
    printf("\n %d Inserted Succesfull \n", X);
}
// pop
int pop(stack *s)
{
    int temp;
    // check empty or not
    if (s->top == -1)
    {
        printf("\n Stack underflow\n");
        exit(1);
    }
    temp = s->arr[s->top];
    s->top--;
    return temp;
}
// display
void display(stack *s)
{
    int i;
    if (s->top == -1)
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("Stack element are:");
    for (i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}
