#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int gener_numer()
{
    int number = 0;
    srand((unsigned)time(NULL));  // 设置种子, time函数获取当前时间 

    int n1 = rand() % 10;
    int n2 = rand() % 10;
    int n3 = rand() % 10;
    int n4 = rand() % 10;

    printf("n1 = %d\n", n1);
    printf("n2 = %d\n", n2);
    printf("n3 = %d\n", n3);
    printf("n4 = %d\n", n4);

    number += n1 * 1000;
    number += n2 * 100;
    number += n3 * 10;
    number += n4;

    printf("number = %d\n", number);
    return number;
}

void gmaeLogic()
{  
    puts("系统随机产生一个四位数.");
    int n = gener_numer();
    int in = 0;
    while(true)
    {
        printf("\n请输入一个4位数: ");
        if(scanf("%d", &in) == 0 || in > 9999 || in < 1000)
        {
            puts("输入格式有误，请重新输入");
            
            continue;

        }
        
        if(in == n)
        {
            puts("猜对了");
            break;
        }

        // 判断第一位
        if(in / 1000 % 10 > n / 1000 % 10)
            puts("第1位大于正确数字");
        else if(in / 1000 % 10 < n / 1000 % 10)
            puts("第1位小于正确数字");
        else
            puts("第1位正确");

        // 判断第二位
        if(in / 100 % 10 > n / 100 % 10)
            puts("第2位大于正确数字");
        else if(in / 100 % 10 < n / 100 % 10)
            puts("第2位小于正确数字");
        else
            puts("第2位正确");

        // 判断第三位
        if(in / 10 % 10 > n / 10 % 10)
            puts("第3位大于正确数字");
        else if(in / 10 % 10 < n / 10 % 10)
            puts("第3位小于正确数字");
        else
            puts("第3位正确");

        // 判断第四位
        if(in % 10 > n % 10)
        {

        }
        if(in % 10 > n % 10)
            puts("第4位大于正确数字");
        else if(in % 10 < n % 10)
            puts("第4位小于正确数字");
        else
            puts("第4位正确");
        
    }
    
}

int main(void)
{
    gmaeLogic();


    return 0;
}