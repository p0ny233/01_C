#include <stdio.h>

void PrintArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr[] = {2, 5, 3, 7, -1, -8};
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            int tmp = 0;
            if(arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    PrintArr(arr, len);
    
    return 0;
}