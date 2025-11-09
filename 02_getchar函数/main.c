#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// scanf
void test01()
{
    char c;
    scanf("%c", &c);
    printf("test01 %c\n", c);
}

void test02()
{
    char ch = getchar();
    printf("test02 %c\n", ch);
}

int main(void)
{
#if 0
    test01();
#else
    test02();
#endif


    return 0;
}