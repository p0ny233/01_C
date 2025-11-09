#include <stdio.h>

int main(void)
{
    char ch = 0;

    FILE *fp = fopen("./a.txt", "w+");  // fgetc 需要有可读模式
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    printf("fopen: success\n");
   
    // 读写内容
    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);
    fflush(fp);

    // 文件流指针在末端，需要调整到开头，才能往后读取字符
    rewind(fp);
    
    while((ch = fgetc(fp)) != EOF)  // 需要加括号，先运算赋值运算符
        printf("%c\t", ch);

    if(fp)
        fclose(fp);
    return 0;
}
