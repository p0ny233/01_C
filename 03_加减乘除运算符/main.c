#include <stdio.h>

int main(void)
{
    int num = 123456;
    
    int a = num % 10;           // 个位
    int b = num / 10 % 10;      // 十位
    int c = num / 100 % 10;     // 百位
    int d = num / 1000 % 10;    // 千位
    int e = num / 10000 % 10;   // 万位
    int f = num / 100000 % 10;  // 十万位
    printf("a = %d\n", a);  
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    return 0;
}
