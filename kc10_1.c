/* @date: 2020-08-28 21:41:00
@功能:

@目的:
链表雏形，但是所定义的结构体中没有定义结构体变量指针，不完整
*/


# include <stdio.h>
# include <malloc.h>
#include <string.h>
struct Student 
{
    int age;
    char name[101];
};
struct Student * CreatList(void);
void TraverseList(struct Student * );

int main (void)
{
    struct Student * pst;
    pst=CreatList();
    TraverseList(pst);


    return 0;
}
struct Student * CreatList(void)
{
    printf("%ld\n",sizeof(struct Student)); // 思考这里为什么是１０８个
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    p->age=10;
    strcpy(p->name,"lisi");
    return p;
}
void TraverseList(struct Student * pst)
{   
    printf("name = %s\n",pst->name);
    printf("age = %d\n",pst->age);
    return ;
}