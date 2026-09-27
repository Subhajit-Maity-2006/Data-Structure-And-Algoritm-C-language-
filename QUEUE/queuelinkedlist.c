#include <stdio.h>
#include <stdlib.h>

// Structure declaration
struct node
{
    int val;
    struct node *next;
};

// Queue pointers
struct node *front = NULL;
struct node *rear = NULL;


// Function declarations
int isEmpty();
void insert(int x);
int delete();
int peek();
void display();


// Main function
int main()
{
    int choice;
    int x;

    while (1)
    {
        printf("\n\n----- QUEUE USING LINKED LIST -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check Empty\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                x = delete();

                if (x != -1)
                {
                    printf("Deleted element = %d\n", x);
                }
                break;

            case 3:
                x = peek();

                if (x != -1)
                {
                    printf("Front element = %d\n", x);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                if (isEmpty())
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    printf("Queue is not empty\n");
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


// Check whether queue is empty
int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Insert a new element into queue
void insert(int x)
{
    struct node *new;

    new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("Memory allocation unsuccessful\n");
        return;
    }

    new->val = x;
    new->next = NULL;

    // Queue is empty
    if (rear == NULL)
    {
        front = new;
        rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }

    printf("%d inserted into queue\n", x);
}


// Delete an element from queue
int delete()
{
    struct node *temp;
    int x;

    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    temp = front;
    x = temp->val;

    front = front->next;

    // If queue becomes empty
    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);

    return x;
}


// Return front element
int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    return front->val;
}


// Display queue
void display()
{
    struct node *temp;

    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\n");
}
