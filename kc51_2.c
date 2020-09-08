# include <stdio.h>

void f(int n)
{
    if (n == 1)
        printf("haha!\n");
    else 
        f(n-1);
    return ;
}
int main (void)
{
    f(3);
    return 0;
}