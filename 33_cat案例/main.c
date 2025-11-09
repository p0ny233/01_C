#include <stdio.h>
// D:\cpp_code\bxg\01_C\33_cat案例\main.c
    
void read_file(FILE* fp)
{
    char ch;

    while(1)
    {
        ch = fgetc(fp);
        if (feof(fp))
            break;
        fputc(ch, stdout);
    }
}

int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        printf("%s file\n", argv[0]);
        return -1;
    }


    FILE *fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror("fopen: ");
        return -1;
    }
    read_file(fp);

    if(fp)
        fclose(fp);

    return 0;
}