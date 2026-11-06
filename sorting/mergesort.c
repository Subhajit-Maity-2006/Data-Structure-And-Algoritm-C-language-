#include <stdio.h>

// Function declarations
void MergeSort(int a[], int p, int r);
void Merge(int a[], int p, int q, int r);

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

    MergeSort(a, 0, n-1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

// Merge Sort Function
void MergeSort(int a[], int p, int r)
{
    int q;

    if(p < r)
    {
        q = (p + r) / 2;

        MergeSort(a, p, q);
        MergeSort(a, q+1, r);

        Merge(a, p, q, r);
    }
}

// Merge Function
void Merge(int a[], int p, int q, int r)
{
    int b[100], l1, r1, i;

    l1 = p;       // Left starting index
    r1 = q + 1;   // Right starting index
    i = p;        // Temporary array index

    while(l1 <= q && r1 <= r)
    {
        if(a[l1] <= a[r1])
        {
            b[i] = a[l1];
            l1 = l1 + 1;
            i = i + 1;
        }
        else
        {
            b[i] = a[r1];
            r1 = r1 + 1;
            i = i + 1;
        }
    }

    while(l1 <= q)
    {
        b[i] = a[l1];
        l1 = l1 + 1;
        i = i + 1;
    }

    while(r1 <= r)
    {
        b[i] = a[r1];
        r1 = r1 + 1;
        i = i + 1;
    }

    for(i = p; i <= r; i++)
    {
        a[i] = b[i];
    }
}
