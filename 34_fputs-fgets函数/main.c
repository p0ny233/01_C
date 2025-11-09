#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test_fputs(FILE **fp)  // 写到指定文件流
{
    char str[] = "字符串写入到指定的文件流";
    *fp = fopen("./test_fputs.txt", "w");
    if(*fp == NULL)
    {
        perror("fopen: ");
        return -1;
    }
    fputs(str, *fp);
    printf("写入成功\n");
}

void test_fgets(FILE** fp)  // 从指定文件流中读取到buffer
{
    char str[1024] = {NULL};
    *fp = fopen("./test_fputs.txt", "r");
    if(*fp == NULL)
    {
        perror("fopen: ");
        return -1;
    }
    fgets(str, sizeof(str), *fp);
    printf("[%s]\n", str);
}

int main(void)
{
    FILE *fp = NULL;
    

    test_fputs(&fp);
    if(fp)
    {
        fflush(fp);
        fclose(fp);

    }
    test_fgets(&fp);
    if(fp)
    {
        fflush(fp);
        fclose(fp);

    }
    return 0;
}