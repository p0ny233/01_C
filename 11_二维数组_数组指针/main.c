#include <stdio.h>

// 1. 二维数组定义方式 
void test01()
{
    printf("\n%s\n", __func__);
    int arr[4][3] =   // 4行3列
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
    };  // 二维数组定义方式一  【可读性最高】

    // 二维数组定义方式二
    int arr1[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // 二维数组定义方式三
    int arr2[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int (*p)[3] = arr;  // 指向第一行数组指针
    
    //int b = p;   // warning C4047: “初始化”:“int”与“int (*)[3]”的间接级别不同
    //int c = *p;  // warning C4047: “初始化”:“int”与“int *”的间接级别不同

    // 通过 p指针访问 元素6
    printf("%d\n", *(*p + 5));    // p 是指向 整个一维数组的指针，*p 后的类型为 int*
    printf("%d\n", *(p[0] + 5));  // 同上
    printf("%d\n", p[1][2]);
    printf("%d\n", *(*(p + 1) + 2));

}
// 二维数组做函数参数

//void printArray(int arr[][3], int row, int col)  // 可读性高，参数一 不同
//void printArray(int arr[4][3], int row, int col) // 可读性高，参数一 不同
void printArray(int (*arr)[3], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            //printf("%d ", arr[i][j]);  // 可读性高
            printf("%d ", *(*(arr + i)) + j);
        }
        printf("\n");

    }
}
void test02()
{
    printf("\n%s\n", __func__);
    int arr[4][3] =   // 4行3列
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
    };  // 二维数组定义方式一  【可读性最高】
    printArray(arr, 4, 3);

    // sizeof
    printf("sizeof: %d\n", sizeof(arr));

    // 取地址
    printf("%d\n", &arr);
    printf("%d\n", &arr + 1);  // 跳过 arr整个数组

    int(*pArr)[4][3] = &arr;
 
}

int main(void)
{
    test01();
    test02();
    return 0;
}