#include <stdio.h>
#include <stdlib.h>

#define size 5

int f = 0;
int r = -1;

// Function declarations
int isEmpty(int q[]);
int isFull(int q[]);
void insert(int q[], int x);
int delete(int q[]);
int peek(int q[]);
void display(int q[]);


// Main function
int main()
{
    int q[size];
    int choice;
    int x;

    while (1)
    {
        printf("\n\n----- QUEUE USING ARRAY -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check Empty\n");
        printf("6. Check Full\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(q, x);
                break;

            case 2:
                x = delete(q);

                if (x != -1)
                {
                    printf("Deleted element = %d\n", x);
                }
                break;

            case 3:
                x = peek(q);

                if (x != -1)
                {
                    printf("Front element = %d\n", x);
                }
                break;

            case 4:
                display(q);
                break;

            case 5:
                if (isEmpty(q))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 6:
                if (isFull(q))
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


// Check whether queue is empty
int isEmpty(int q[])
{
    if (r < f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Check whether queue is full
int isFull(int q[])
{
    if (r == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Insert a new element into queue
void insert(int q[], int x)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    r++;
    q[r] = x;

    printf("%d inserted into queue\n", x);
}


// Delete an element from queue
int delete(int q[])
{
    int temp;

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    temp = q[f];
    f++;

    return temp;
}


// Return front element
int peek(int q[])
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    return q[f];
}


// Display all queue elements
void display(int q[])
{
    int i;

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for (i = f; i <= r; i++)
    {
        printf("%d ", q[i]);
    }

    printf("\n");
}
