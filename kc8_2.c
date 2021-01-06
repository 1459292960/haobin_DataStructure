/* @date: 2020-08-28 20:50:25
@功能:

@目的:
    了解指针的优点
    普通结构体变量和结构体指针变量作为函数传参的问题
*/


# include <stdio.h>
// 自定义了一个结构体变量类型
struct  Student
{
    int sid;
    char name[200];
    int age;
};
void InputStudent (struct Student *);
void OutputStudent(struct Student *);
int main (void)
{
    struct Student st;
    InputStudent(&st);
    OutputStudent(&st); // 只需要发送st的第一个字节的地址,在我的64位电脑中发送了8个字节，
                                                // 节省时间、内存
    return 0;
}
void InputStudent(struct Student * p)
{
    printf("sid = ");
    scanf("%d",&(p->sid));
    printf("name = ");
    scanf("%s",p->name); // p->name 等价于 (*P).name,name是一个一维数组的数组名代表第一个元素的地址，
                                                 // 所以这里不需要再用取地址符 
    printf("age = ");
    scanf("%d",&(p->age));
    return;
}
void OutputStudent(struct Student * p)
{
    printf("sid = %d\n",p->sid);
    printf("sid = %s\n",p->name);
    printf("sid = %d\n",p->age);
    return ;
}