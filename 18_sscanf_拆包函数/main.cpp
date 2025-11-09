#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1024] = "beijing:2025:t:07:28";
    int year = 0;
    int month = 0;
    int day = 0;
    int ret = sscanf(buf, "beijing:%d:t:%d:%d", &year, &month, &day);  // 返回值: 返回拆包成功的个数
        
    printf("ret= %d\n", ret);
    printf("year=%d, month=%d, day=%d\n", year, month, day);
    return 0;
}
/*
ret= 3
year=2025, month=7, day=28
*/
