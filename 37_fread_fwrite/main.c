#include <stdio.h>

typedef struct _std
{
    int id;
    int age;
    char name[16];
} STD;

void test_fwrite()
{
    printf("test_fwrite\n");
    STD infos[] = { 
            {111111, 10, "Lucy"},
            {222222, 20, "Cookie"},
            {333333, 30, "Andy"},
            {444444, 40, "Kimi"},
            };
    
    FILE* fp = fopen("./infos.bin", "wb");
    if(!fp)
    {
        perror("fopen: ");
        return -1;
    }
    
    // fwrite第二个参数：每个数据块的字节数为 1，为了fwrite返回值等于实际写入文件的字节数，因此设置为 1
    // fwrite第三个参数：表示有多少个数据块，也是返回值
    int bytes = fwrite(infos, 1, sizeof(infos), fp);
    
    if(fp)
    {
        fflush(fp);
        fclose(fp);
        printf("write success\n");
    }
}


void test_fread()
{
    STD infos[16] = {0};
    

    printf("test_fread\n");
    FILE* fp = fopen("./infos.bin", "rb");
    if(!fp)
    {
        perror("fopen:");
        return -1;
    }

    int bytes = fread(infos, 1, sizeof(infos), fp);
    for(int i = 0; i < sizeof(infos) / sizeof(STD); i++)
    {
        if ((infos[i].id == 0) && (infos[i].age == 0) && !strcmp(infos[i].name, ""))
            break;
        printf("infos[%d].id: %d, infos[%d].age: %d, infos[%d].name: %s\n", i, infos[i].id, i, infos[i].age, i, infos[i].name);
        
    }
    if(fp)
    {
        fclose(fp);
    }
}


int main(void)
{
    test_fwrite();
    test_fread();

    
    return 0;
}