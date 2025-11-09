#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 获取文件的有效行数
int getLines(FILE *fp)
{
    if(fp == NULL)
    {
        printf("INVALID FILE STREAM");
        return -1;
    }
    int line_num = 0;
    char buf[1024] = {0};
    char *ptr = buf;
    while(fgets(buf, 1024, fp) != NULL)
        line_num++;

    return line_num;
}

// 读取文件内容
void readFileData(FILE *fp, char **pArrayBuffer, int len)
{
    if(fp == NULL)
        return;
    if (pArrayBuffer == NULL)
        return;
    if (len <= 0)
        return;
    char buf[1024] = { 0 };

    // 计算要开辟多大的空间存储字符串
    fseek(fp, 0 ,SEEK_SET);  // 很重要
    // 在 getLines函数中已经获取所有函数导致 文件指针到达文件末尾，因此需要重置指针到文件开始位置

    for(int i = 0; fgets(buf, 1024, fp) != NULL; i++)
    {
        // 开辟空间，将地址给pArrayBuffer
        buf[strlen(buf) - 1] = 0;  // 去除fgets自动添加的换行符
        pArrayBuffer[i] = malloc(strlen(buf) + 1);
        memset(pArrayBuffer[i], 0, strlen(buf) + 1);
        strcpy(pArrayBuffer[i], buf);

        memset(buf, 0, 1024);
    }
}

// 显示文件内容
void showFileData(char** pArrayBuffer, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%s\n", pArrayBuffer[i]);
    }
}

void test01()
{
    FILE* fp = fopen("./test.txt", "r");
    if(fp == NULL)
    {
        puts("文件打开错误");
        return;
    }
    int len = getLines(fp);
    char **pArrayBuffer = malloc(sizeof(void*) * len);
    memset(pArrayBuffer, 0, sizeof(void*) * len);

    // 读取文件内容到缓冲区
    readFileData(fp, pArrayBuffer, len);

    // 显示文件内容
    showFileData(pArrayBuffer, len);

    // 释放堆区空间
    for(int i = 0; i < len; i++)
    {
        free(pArrayBuffer[i]);
    }
    free(pArrayBuffer);
    pArrayBuffer = NULL;

    fclose(fp);
    fp = NULL;

}


int main(void)
{

    test01();
    return 0;
}