#include <stdio.h>

#define MAX 100

// Function declaration
void degree(int adj[MAX][MAX], int n);

int main()
{
    int n;
    int adj[MAX][MAX];
    char ch;

    printf("Enter number of vertex: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                printf("Vertices %d & %d are Adjacent ? (Y/N) : ",
                       i + 1, j + 1);

                scanf(" %c", &ch);

                if(ch == 'Y' || ch == 'y')
                    adj[i][j] = 1;
                else
                    adj[i][j] = 0;
            }
        }
    }

    // Function call
    degree(adj, n);

    return 0;
}

// Function definition
void degree(int adj[MAX][MAX], int n)
{
    printf("\nVertex\tIn_Degree\tOut_Degree\tTotal_Degree\n");

    for(int i = 0; i < n; i++)
    {
        int in_degree = 0;
        int out_degree = 0;

        for(int j = 0; j < n; j++)
        {
            // Row = outgoing edges
            out_degree += adj[i][j];

            // Column = incoming edges
            in_degree += adj[j][i];
        }

        printf("%d\t%d\t\t%d\t\t%d\n",
               i + 1,
               in_degree,
               out_degree,
               in_degree + out_degree);
    }
}
