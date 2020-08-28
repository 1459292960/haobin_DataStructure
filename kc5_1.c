/* @date: 2020-08-28 19:10:15
@功能:

@目的:
了解指针的作用
*/


# include <stdio.h>
void f(int * p)
{
    *p=100;
    return;
}
int main (void)
{
    int i=10;
    f(&i); // 通过传递地址才能在另外一个函数中修改变量的值
    printf("%d\n",i);
    return 0;
}