#include <stdio.h>

#define MAX 100

// Function declaration
void BFS(int adj[MAX][MAX], int n, int start);

int main()
{
    int n;
    int adj[MAX][MAX];
    int start;

    printf("Enter number of vertex: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    // Function call
    BFS(adj, n, start);

    return 0;
}

// Function definition
void BFS(int adj[MAX][MAX], int n, int start)
{
    int flag[MAX];

    int queue[MAX];
    int front = 0;
    int rear = -1;

    // 1. Set flag = 1 for all nodes
    for(int i = 0; i < n; i++)
    {
        flag[i] = 1;
    }

    // 2. Enqueue first node
    queue[++rear] = start;

    // 3. Set flag = 2 for start node
    flag[start] = 2;

    printf("Breadth First Search: ");

    // 4. Repeat until queue is empty
    while(front <= rear)
    {
        // 5. Dequeue
        int x = queue[front++];

        // 6. Process x
        printf("%d ", x);

        // 7. Set flag = 3
        flag[x] = 3;

        // 8. Check all neighbours of x
        for(int y = 0; y < n; y++)
        {
            // If y is connected and unvisited
            if(adj[x][y] == 1 && flag[y] == 1)
            {
                // Enqueue y
                queue[++rear] = y;

                // Set flag = 2
                flag[y] = 2;
            }
        }
    }

    printf("\n");
}
