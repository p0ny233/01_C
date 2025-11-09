#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[] = "                hello world       ";
    char res_buf[1024] = {0};
    char *p1 = buf;                    // 头指针
    char *p2 = &buf[strlen(buf) - 1];  // 尾指针

    while (*p1 == ' ')
       p1++;
    
    while (*p2 == ' ')
       p2--;
    
    // 经过循环后， p1指向 h字符，p2指向 d字符

    int cpy_number =  p2 - p1 + 1;
    strncpy(res_buf, p1, cpy_number);
    printf("[%s]", res_buf);
    return 0;
}
/*
[hello world]
*/