#include <stdio.h>
#include <stdbool.h>

void printArray(int * arr, int len)
{   
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}
void mySort()
{
    int arr[] = {3, 4, 1, 2, 6, 0, 0, 1};
    int len = sizeof(arr) / sizeof(arr[0]);  // 5
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        int min = i;
        for(j = i+1; j < len; j++)
        {
            if(arr[min] > arr[j])
                min = j;

        }
        
        // swap
        if(min != i)
        {
            arr[i] = arr[i] ^ arr[min];
            arr[min] = arr[i] ^ arr[min];
            arr[i] = arr[i] ^ arr[min];
        }
        
    }
    printArray(arr, len);

}

int main(void)
{
    mySort();
    


    return 0;
}