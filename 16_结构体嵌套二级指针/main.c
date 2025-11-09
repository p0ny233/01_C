// 未实现完
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct
{
    char* s_no;
    char* name;
} Student;


typedef struct
{
    char *t_no;
    char *name;
    Student**Students;
} Teacher;



void initTeacher(Teacher **tarr, int len)
{
    for(int i = 0; i < len; i++)
    {
        tarr[i] = (Teacher*)malloc(sizeof(Teacher));
        tarr[i]->t_no = malloc(64);
        tarr[i]->name = malloc(64);
        
        srand(NULL);
        int r = rand() % 8 + 1;
        unsigned n = r << 16;
        char c = 'a' + i;
        for(int j = 1; j < 11; j++)
        {
            char buf[1024] = "";
            Student* s = (Student*)malloc(sizeof(Student));
            s->s_no = (char*)malloc(64);
            s->name = (char*)malloc(64);
            sprintf(buf, "%d", n+j);
            strcpy(s->s_no, buf);
            memset(buf, 0, 1024);
            sprintf(buf, "%c%d", c, j);
            strcpy(s->name, buf);

            
        }
    }
}

void test01()
{
    Teacher* tarr[3];
    
    initTeacher(tarr, sizeof(tarr) / sizeof(tarr[0]));
}

int main(void)
{
    
}