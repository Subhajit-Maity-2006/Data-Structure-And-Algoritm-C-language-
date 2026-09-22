#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int val;
    struct stack *next;
};
struct stack *push(struct stack *top, int x);
struct stack *pop(struct stack *top);
void display(struct stack *top);

int main()
{
    struct stack *top = NULL;
    int choice, x;

    while (1)
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &x);

            top = push(top, x);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            display(top);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
// push
struct stack *push(struct stack *top, int x)
{
    struct stack *new;
    new = (struct stack *)malloc(sizeof(struct stack));
    if (new == NULL)
    {
        printf("\nMemory is not allocated\n");
        exit(1);
    }
    new->val = x;
    new->next = top;
    top = new;
    printf("Inserted succesfull");
    return top;
}
// pop
struct stack *pop(struct stack *top)
{
    struct stack *temp;
    if (top == NULL)
    {
        printf("\nStack is empty\n");
        return top;
    }
    temp = top;
    printf("Deleted item is :%d", top->val);
    top = temp->next;
    free(temp);
    return top;
}
// display
void display(struct stack *top)
{
    if (top == NULL)
    {
        printf("Stack is empty");
        return;
    }
    printf("Stack elements are:");
    while (top != NULL)
    {
        printf("%d\n", top->val);
        top = top->next;
    }
}
