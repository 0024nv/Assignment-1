
#include <stdio.h>
#include <time.h>

void swap(long long int *x, long long int *y)
{
    long long int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void display(long long int *a, long long int s)
{
    for (long long int j = 0; j < s; j++)
    {
        printf("%lld ", a[j]);
    }
}
void Bubble_sort()
{
    long long int size;
    printf("Enter size of array: ");
    scanf("%lld", &size);
    long long int arr[size];
    printf("Enter elsements of array: \n");
    for (long long int i = 0; i < size; i++)
    {
        scanf("%lld", arr + i);
    }

    printf("\nArray before sorting: \n");
    display(arr, size);

    for (int i = 0; i < size - 1; i++) 
    {
        int x = 1;                             
        for (long long int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
                x = x * 0;
            }
            else
            {
                x = x * 1;
            }
        }
        if (x != 0)
            break;
    }
    printf("\nArray after sorting: \n");
    display(arr, size);
}
void Selection_sort()
{
    long long int size;
    printf("Enter size of array: ");
    scanf("%lld", &size);
    long long int arr[size];
    printf("Enter elsements of array: \n");
    for (long long int i = 0; i < size; i++)
    {
        scanf("%lld", arr + i);
    }

    printf("\nArray before sorting: \n");
    display(arr, size);

    long long int i = 0;
    while (i < size - 1)
    {
        long long int ind_min = i;
        long long int j = i + 1;
        while (j < size)
        {
            if (arr[ind_min] > arr[j])
            {
                ind_min = j;
            }
            j++;
        }
        swap(arr + ind_min, arr + i);
        i++;
    }
    printf("\nArray after sorting: \n");
    display(arr, size);
}
int main()
{
    clock_t start, end;
    long int t;
    start = clock();

    // Bubble_sort();
    Selection_sort();

    end = clock();
    t = end - start;
    printf("\nTotal elapsed time: %f ", (double)t / (double)CLOCKS_PER_SEC);

    return 0;
}