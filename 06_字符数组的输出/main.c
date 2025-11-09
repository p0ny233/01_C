#include <stdio.h>

// puts: 自动在末尾添加 \n.
void test01()
{
    char str[] = "test01 hello World";
    puts(str);
}

// fputs: 末尾没有\n，需手动指定流.
void test02()
{
    char str[] = "test02 hello World";
    fputs(str, stdout);
    fputs(str, stdout);
}

int main(void)
{
    test01();
    test02();
}