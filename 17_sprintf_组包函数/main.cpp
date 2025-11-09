#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1024] = "";
    int year = 2025;
    int month = 7;
    int day = 28;
    int len = sprintf(buf, "year=%d, month=%02d, day=%02d\n", year, month, day);
    // len为 sprintf函数的返回值，返回成功组包后的字节数

    printf("%s", buf);
    printf("len = %d\n", len);
    return 0;
}
/*
year=2025, month=07, day=28
len = 28
*/