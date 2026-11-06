#include <stdio.h>

// Function declarations
void QuickSort(int a[], int p, int r);
int PARTITION(int a[], int p, int r);

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    QuickSort(a, 0, n-1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

// Quick Sort Function
void QuickSort(int a[], int p, int r)
{
    int q;

    if(p < r)
    {
        q = PARTITION(a, p, r);

        QuickSort(a, p, q);
        QuickSort(a, q+1, r);
    }
}

// Partition Function
int PARTITION(int a[], int p, int r)
{
    int x, i, j, temp;

    x = a[p];       // Pivot element
    i = p - 1;
    j = r + 1;

    while(1)
    {
        do
        {
            j = j - 1;
        }
        while(a[j] > x);

        do
        {
            i = i + 1;
        }
        while(a[i] < x);

        if(i < j)
        {
            // Swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            return j;
        }
    }
}
