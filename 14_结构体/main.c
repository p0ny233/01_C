
// 结构体定义方式一
typedef struct Person
{
    //int age = 8;                // 1. C语言的结构体不可以给成员赋初始值
    //char name[255] = "Hello";   // 1. C语言的结构体不可以给成员赋初始值
    char name[64];
    int age;
    //void func();   // 2. C语言结构体不可以放函数


} PersonType;  // 给结构体起别名为 PersonType，PersonType相当于 struct Person

// 结构体定义方式二
struct Person2
{
    char name[64];
    int age;
}myPerson2  = {"world", 10};  // myPerson2 是一个结构体变量


// 结构体定义方式三
struct 
{
    char name[64];
    int age;
} p2;  // 匿名类型的结构体，定义p2结构体变量，使用频率低  




int main(void)
{
    PersonType p1 = {"john", 11};

}