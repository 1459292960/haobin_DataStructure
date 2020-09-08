# include <stdio.h>

void f()
{   
    printf("haha!\n");
    f(); // 自己调用自己，但找不到出口，直到出错
    return ;
}
int main (void)
{
    f();
    return 0;
}