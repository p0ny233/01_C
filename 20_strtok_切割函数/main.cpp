#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1024] = "13652365232#bangquna#2616161#1111@qq.com&pass=admin";
    char *ptrs[10] = {NULL};
    
    int i = 0;
    do
    {
        if(i == 0)
            ptrs[i] = strtok(buf, "#@&");
        else
            ptrs[i] = strtok(NULL, "#@&");
    }while (ptrs[i++] != NULL);

    i = 0;
    while(ptrs[i] != NULL)
        printf("%s\n", ptrs[i++]);

    return 0;
}
/*
13652365232
bangquna
2616161
1111
qq.com
pass=admin

D:\cpp_code\bxg\01_C\x64\Debug\20_strtok_切割函数.exe (进程 4200)已退出，代码为 0。
*/