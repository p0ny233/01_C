#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char num1[] = "\n\r+123";  // 有空白字符
    char num2[] = "\n\r-124";  // 有空白字符
    int n1 = atoi(num1);  // 将num1转为 整型
    int n2 = atoi(num2);
    printf("%d %d\n", n1, n2);  // 123 -124
    
    char fnum1[] = "\n\r+1.23";
    char fnum2[] = "\n\r-1.24";
    float f1 = atof(fnum1);
    float f2 = atof(fnum2);
    printf("%f %f", f1, f2);  // 1.230000 -1.240000

    return 0;
}

/*
123 -124
1.230000 -1.240000
*/