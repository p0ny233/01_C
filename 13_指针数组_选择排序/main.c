#include <stdio.h>

void printArray(char** arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%s\n", arr[i]);
    }
}

void stringSort()
{
    char * arr[] = {"aaa", "bbb", "ccc", "ddd", "fff", "eee"};  // 指针数组
        
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < len; i++)
    {
        int max = i;
        for(int j = i + 1; j < len; j++)
        {
            //if (arr[max][0] < arr[j][0])  // 比较两个字符串的首个字符
            if(strcmp(arr[max], arr[j]) == -1)  // 后者大于 前者
                max = j;
        }
        
        // swap
        if(max != i)
        {
            char *tmp = arr[max];
            arr[max] = arr[i];
            arr[i] = tmp;

            
        }
    }
    
    printArray(arr, len);

}


int main(void)
{

    stringSort();
    return 0;
}