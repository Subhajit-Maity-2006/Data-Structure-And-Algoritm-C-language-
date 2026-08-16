#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// Create structure
struct sll
{
    int val;
    struct sll *next;
};
// Create funciton
void createlist(struct sll *);
void display(struct sll *);
int count(struct sll *);
void insertnode(struct sll **);
void searchnode(struct sll *);
void insertend(struct sll *);
void deletebegin(struct sll **);
void deleteend(struct sll**);
int main()
{
    struct sll *node;
    int choice;
    // Object created but size in not allocated
    node = (struct sll *)malloc(sizeof(struct sll)); // Size allocated
    // Check size allocated or not
    if (node == NULL)
    {
        printf("Memory is not allocated");
        exit(1); // allocation fail
    }
    node->next = NULL;
    do
    {
        printf("\n\n--------LINKED LIST MENU--------");
        printf("\n1. Create List");
        printf("\n2. Display List");
        printf("\n3. Count Nodes");
        printf("\n4. Insert at Beginning");
        printf("\n5. Search the node:");
        printf("\n6. Insert the node at the end of the list:");
        printf("\n7: Delete the node from begine:");
        printf("\n8. Delete the node from end:");
        printf("\n9. Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createlist(node);
            break;
        case 2:
            display(node);
            break;
        case 3:
            printf("\nNo of nodes:%d", count(node));
            break;
        case 4:
            insertnode(&node);
            break;
        
            case 5:
            searchnode(node);
            break;

            case 6:
            insertend(node);
            break;
            case 7:
            deletebegin(&node);
            break;

            case 8:
            deleteend(&node);
            break;
            case 9:
            printf("\n Ended program");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 9);
    return 0;
}
// creating a single linked list dynamically
void createlist(struct sll *node)
{
    char ch;
    int i = 1;

    printf("Enter the value of %d node: ", i);
    scanf("%d", &node->val);

    node->next = NULL;
    i++;

    printf("\nEnter q to quit and any other key to continue: ");
    scanf(" %c", &ch);

    // Remove remaining characters from input buffer
    while(getchar() != '\n');

    while(ch != 'q')
    {
        node->next = (struct sll *)malloc(sizeof(struct sll));

        if(node->next == NULL)
        {
            printf("Memory is not allocated");
            exit(1);
        }

        node = node->next;

        printf("\nEnter the value of %d node: ", i);
        scanf("%d", &node->val);

        node->next = NULL;
        i++;

        printf("\nEnter q to quit and any other key to continue: ");
        scanf(" %c", &ch);

        // Remove remaining characters from input buffer
        while(getchar() != '\n');
    }
}

// display the single linked list
void display(struct sll *node)
{
    printf("\nThe elements are: ");

    while (node != NULL)
    {
        printf("%d -> ", node->val);
        node = node->next;
    }

    printf("NULL");
}

// Counting the no of the node
int count(struct sll *node)
{
    int count = 0;
    while (node != NULL)
    {
        count++;
        node = node->next;
    }
    return count;
}

// INSERT A NEW NODE AT THE BEGINING
void insertnode(struct sll **start)
{
    struct sll *new;

    new = (struct sll *)malloc(sizeof(struct sll));

    if (new == NULL)
    {
        printf("\nInsufficient memory\n");
        exit(1);
    }

    printf("Enter value: ");
    scanf("%d", &new->val);

    new->next = *start;
    *start = new;
}
//SEARCH AN ELEMENT IN SLL
void searchnode(struct sll *node){
    int value;
    int position=1;
    int found=0;
    printf("\nEnter the value of the node:");
    scanf("%d",&value);
    //LOGIC
    while(node!= NULL){
        if(node->val == value){
            printf("\n%d found at the position at: %d",value,position);
            found=1;
            break;
        }
          node=node->next;
        position++;
    }
        if(found==0){
            printf("The element is not found");
        }
}

//INSERT A NODE AT LAST OF THE LIST
void insertend(struct sll * node){
    struct sll* new;
    new=(struct sll *)malloc(sizeof(struct sll));
    if(new==NULL){
        printf("Memory is not alloacated");
        exit (1);
    }
    printf("Enter the value:");
    scanf("%d",&new->val);
     new->next = NULL;
    //TRAVERSE TO THE END AND STOP THERE
    while(node->next != NULL){
        node=node->next; 
    }
    node->next = new;// new ka value null wala node-> next main dal dena 
}
// DELETE THE NODE FROM BEGINE
void deletebegin(struct sll **node)
{
    struct sll *temp;

    if(*node == NULL)
    {
        printf("\nEmpty list\n");
        return;
    }

    temp = *node;
    *node = (*node)->next;

    free(temp);
}

void deleteend(struct sll **node)
{
    struct sll *temp, *prev;

    // Empty list
    if(*node == NULL)
    {
        printf("\nEmpty list\n");
        return;
    }

    // Only one node
    if((*node)->next == NULL)
    {
        free(*node);
        *node = NULL;
        return;
    }

    temp = *node;
    prev = NULL;

    // Traverse to the last node
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // Delete last node
    free(temp);

    // Make second-last node the last node
    prev->next = NULL;
}