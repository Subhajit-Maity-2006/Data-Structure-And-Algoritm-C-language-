#include <stdio.h>

// Function declarations
void Heapify(int a[], int i, int n);
void BuildHeap(int a[], int n);
void HeapSort(int a[], int n);
void swap(int *x, int *y);

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

    HeapSort(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

// Heapify Function
void Heapify(int a[], int i, int n)
{
    int l, r, largest, temp;

    l = 2 * i + 1;       // Left child
    r = 2 * i + 2;       // Right child

    largest = i;

    if(l < n && a[l] > a[largest])
    {
        largest = l;
    }

    if(r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        Heapify(a, largest, n);  // Recursive call
    }
}

// Build Heap Function
void BuildHeap(int a[], int n)
{
    int i;

    for(i = (n - 2) / 2; i >= 0; i--)
    {
        Heapify(a, i, n);
    }
}

// Swap Function
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// Heap Sort Function
void HeapSort(int a[], int n)
{
    int i;

    BuildHeap(a, n);

    for(i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);

        Heapify(a, 0, i);
    }
}
