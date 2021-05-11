/* @date: 2020-08-28 19:58:47
@功能:

@目的:
    修改指针变量的值
*/


#include <stdio.h>
void f(int **);
int main (void)
{
    int i=9;
    int * p;
    p=&i;
    printf("%p\n",p);
    f(&p); // 修改指针变量的值，也只需要传递该变量的地址
    printf("%p\n",p);
    return 0;
}
void f(int ** q) // int ** 类型只能存放 int *类型变量的地址
{
    *q=(int *)0xFFFFFFFFFFFFFFFF; // p指向了内存编号为0xFFFFFFFFFFFFFFFF的单元，
                                   // 这样做是很危险的，因为该内存并没有分配给该程序
    return ;
}

/*在VScode中的输出：
0x7ffc1f4a919c
0xffffffffffffffff
总结：

*/
