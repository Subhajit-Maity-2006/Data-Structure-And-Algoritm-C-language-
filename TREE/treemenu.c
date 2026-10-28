#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *lc;
    struct node *rc;
};

typedef struct node *bstnode;

// Function declarations
bstnode makeBST(bstnode);
bstnode insertBST(bstnode, int);
bstnode Find(bstnode, int);
bstnode Findmin(bstnode);
bstnode Findmax(bstnode);
bstnode deleteBST(bstnode, int);
void freeBST(bstnode);

int main() {
    bstnode root = NULL;
    int choice, x;

    do {
        printf("\n----- BST MENU -----\n");
        printf("1. Create an empty BST\n");
        printf("2. Insert a new element\n");
        printf("3. Delete a node\n");
        printf("4. Find maximum element\n");
        printf("5. Find minimum element\n");
        printf("6. Search an element\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                freeBST(root);
                root = makeBST(NULL);
                printf("Empty BST created successfully.\n");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                root = insertBST(root, x);
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &x);

                if (Find(root, x) == NULL) {
                    printf("Element not found.\n");
                } else {
                    root = deleteBST(root, x);
                    printf("Element deleted successfully.\n");
                }
                break;

            case 4: {
                bstnode p = Findmax(root);

                if (p == NULL)
                    printf("BST is empty.\n");
                else
                    printf("Maximum element = %d\n", p->val);

                break;
            }

            case 5: {
                bstnode p = Findmin(root);

                if (p == NULL)
                    printf("BST is empty.\n");
                else
                    printf("Minimum element = %d\n", p->val);

                break;
            }

            case 6:
                printf("Enter element to search: ");
                scanf("%d", &x);

                if (Find(root, x) != NULL)
                    printf("Element found in BST.\n");
                else
                    printf("Element not found.\n");

                break;

            case 0:
                freeBST(root);
                root = NULL;
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

// Create an empty BST
bstnode makeBST(bstnode t) {
    return NULL;
}

// Insert a node into BST
bstnode insertBST(bstnode t, int x) {
    if (t == NULL) {
        t = (bstnode)malloc(sizeof(struct node));

        if (t == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }

        t->val = x;
        t->lc = NULL;
        t->rc = NULL;

        return t;
    }

    if (x < t->val) {
        t->lc = insertBST(t->lc, x);
    }
    else if (x > t->val) {
        t->rc = insertBST(t->rc, x);
    }
    else {
        printf("Duplicate element not allowed.\n");
    }

    return t;
}

// Search an element in BST
bstnode Find(bstnode t, int x) {
    if (t == NULL)
        return NULL;

    else if (x < t->val)
        return Find(t->lc, x);

    else if (x > t->val)
        return Find(t->rc, x);

    else
        return t;
}

// Find minimum element
bstnode Findmin(bstnode t) {
    if (t == NULL)
        return NULL;

    else if (t->lc == NULL)
        return t;

    else
        return Findmin(t->lc);
}

// Find maximum element
bstnode Findmax(bstnode t) {
    if (t == NULL)
        return NULL;

    else if (t->rc == NULL)
        return t;

    else
        return Findmax(t->rc);
}

// Delete a node from BST
bstnode deleteBST(bstnode t, int x) {
    bstnode temp;

    if (t == NULL)
        return NULL;

    else if (x < t->val)
        t->lc = deleteBST(t->lc, x);

    else if (x > t->val)
        t->rc = deleteBST(t->rc, x);

    else {
        // Case 1: No child
        if (t->lc == NULL && t->rc == NULL) {
            free(t);
            return NULL;
        }

        // Case 2: Only right child
        else if (t->lc == NULL) {
            temp = t->rc;
            free(t);
            return temp;
        }

        // Case 2: Only left child
        else if (t->rc == NULL) {
            temp = t->lc;
            free(t);
            return temp;
        }

        // Case 3: Two children
        else {
            temp = Findmin(t->rc);
            t->val = temp->val;
            t->rc = deleteBST(t->rc, temp->val);
        }
    }

    return t;
}

// Free all nodes in BST
void freeBST(bstnode t) {
    if (t != NULL) {
        freeBST(t->lc);
        freeBST(t->rc);
        free(t);
    }
}
