#include <stdio.h>

// 1. 先定义出数组的类型，再通过类型定义出数组指针
void test01()
{
    printf("%s\n", __func__);
    int arr[5] = { 1, 0 ,2, 3, 4 };

    typedef int(ARRAY_TYPE)[5];
    ARRAY_TYPE* arrp = &arr;
    for(int i = 0; i < 5; i++)
        printf("%d ", (*arrp)[i]);  // * 比 [] 优先级低，需要括号
}

// 2. 先定义出数组指针的类型，再通过类型创建数组指针变量
void test02()
{
    printf("\n%s\n", __func__);
    int arr[5] = { 1, 0 ,2, 3, 4 };

    typedef int(*ARRAY_TYPE)[5];
    ARRAY_TYPE arrp = &arr;
    for(int i = 0; i < 5; i++)
        printf("%d ", (*arrp)[i]);  // * 比 [] 优先级低，需要括号
}

// 3. 直接定义数组指针变量
void test03()
{
    printf("\n%s\n", __func__);
    int arr[5] = { 1, 0 ,2, 3, 4 };

    int(*arrp)[5] = &arr;
    for(int i = 0; i < 5; i++)
        printf("%d ", (*arrp)[i]);  // * 比 [] 优先级低，需要括号
}

int main(void)
{
    test01();
    test02();
    test03();

    return 0;
}