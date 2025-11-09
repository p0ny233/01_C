#include <stdio.h>



int main(void)
{

    double a = 3.1415;
    int b = 33;
    
    // m.n   其中 m表示的是 宽度， n表示的是有多少个小数
    printf("[%10.4lf]\n", a);    // [    3.1415]   右对齐
    printf("[%-10.4lf]\n", a);    // [3.1415    ]  左对齐

    printf("[%d]\n", b);         // [33]
    printf("[%6d]\n", b);        // [    33]       右对齐
    printf("[%-6d]\n", b);       // [33    ]       左对齐
    printf("[%06d]\n", b);       // [000033]       右对齐补0
    printf("[%-06d]\n", b);      // [33    ]       左对齐

    return 0;
}