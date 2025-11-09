#include <stdio.h>

int main(void)
{
    int year = 2025;
    int month = 8;
    int day = 10;

    FILE *fp = fopen("./test_fprintf.txt", "w");
    if(fp == NULL)
    {
        perror("fopen: ");
        return -1;
    }

    fprintf(fp, "%d:%02d:%02d\n", year, month, day);
    if (fp)
        fclose(fp);

    return 0;
}