// 注意是 .c 文件
#include <stdio.h>

struct Stu
{
    int id;
    int age;
    char name[128];
};

int main(void)
{
    // 初始化方式 1，所有元素都被初始化
    struct Stu s = {123, 22, "unbuntu"};
    printf("s.id: %d\n", s.id);
    printf("s.age: %d\n", s.age);
    printf("s.name: [%s]\n", s.name);

    printf("\n");
    // 初始化方式 2，部分元素初始化，其它成员内容为 0，该语法仅允许 C语言，cpp报错
    struct Stu d = {.age=20};

    printf("d.id: %d\n", d.id);
    printf("d.age: %d\n", d.age);
    printf("d.name: [%s]\n", d.name);
    
    return 0;
}

/*
s.id: 123
s.age: 22
s.name: [unbuntu]

d.id: 0
d.age: 20
d.name: []

*/