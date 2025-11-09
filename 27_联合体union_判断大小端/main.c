#include <stdio.h>

union uType
{
    char a;
    short b;
    int c;
};

int main(void)
{
    
    union uType u;
    u.c = 0x12345678;
    printf("u.a : 0x%x\n", u.a);  // 0x78
    // 根据输出结果，可以得到该系统使用小端


    return 0;
}