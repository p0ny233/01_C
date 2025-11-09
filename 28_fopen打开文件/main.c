#include <stdio.h>

int main(void)
{
    //FILE *fp = fopen("./a.txt", "r");
    FILE *fp = fopen("./a.txt", "w");
    if(fp == NULL)
    {
        perror("fopen");
    }
    else
    {
        printf("fopen: Success");
    }
    return 0;
}