#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// scanf
// 1. 对含有空格等空白字符的字符串不友好
// 2. 写入的目标地址空间不够大，则会造成内存污染
void test01()
{
    char str[128] = "";
    scanf("%s", str);
    printf("[%s]", str);
}


// gets
// 1. 对含有空格等空白字符的字符串友好，遇到 \n结束，不会把 \n 读进来
// 2. 写入的目标地址空间不够大，则会造成内存污染
void test02()
{
    char str[3] = "";
    gets(str);
    printf("[%s]", str);
}

// fgets
// 1. 对含有空格等空白字符的字符串友好，遇到 \n结束，但会把\n 读进来
// 2. 手动指定读取的字节数，内存不会被污染
void test03()
{
    char str1[1024] = "";
    fgets(str1, sizeof(str1), stdin);
    printf("[%s]", str1);
    str1[strlen(str1) - 1] = '\0';
    putchar('\n');
    printf("[%s]", str1);
}

int main(void)
{
    //test01();
    //test02();
    test03();

    return 0;
}