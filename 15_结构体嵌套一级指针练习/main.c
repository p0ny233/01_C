#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int age;
} Person;

void printPersonInfo(Person** arr, int len)
{
    for(int i = 0; i < len; i++)
        printf("姓名: %s， 年龄: %d\n", arr[i]->name, arr[i]->age);
}

void Free(Person** arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        free(arr[i]->name);
        free(arr[i]);
    }
}

void test01()
{
    int len = 3;
    Person** arr = malloc(sizeof(Person*) * len);
    for(int i = 0; i < len; i++)
    {   
        char name[64] = "";
        arr[i] = (Person*)malloc(sizeof(Person));
        sprintf(name, "p%d",i);
        arr[i]->name = (char*)malloc(64);
        strcpy(arr[i]->name, name);
        arr[i]->age = 18;
    }
    
    printPersonInfo(arr, len);
    Free(arr, len);
}

int main(void)
{
    
    test01();

    return 0;
}