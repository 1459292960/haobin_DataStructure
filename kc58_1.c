/* @date: 2020-09-08 15:15:27
@功能:
    使用递归求斐波那契数列值
@目的:
    理解递归的思想：n规模问题的解决依赖于 n-1问题的解决而解决
    要求第n个斐波那契数列值，那先求第n-1个斐波那契数列值和第n-2个斐波那契数列值
*/


# include <stdio.h>

int Fibonacci(int n)
{
    if (n == 1)
        return 1;
    else if (n ==2)
        return 2;
    else
    {
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}
int main (void)
{
    int n;
    printf("请输入您想求第几个斐波那契数列值：");
    scanf("%d",&n);
    printf("第%d个斐波那契数列值为%d\n",n,Fibonacci(n));
    return 0;
}

/*@在VScode中的输出：
---------------------------------

---------------------------------
@总结：
    递归的优点：
         易于理解
    递归的缺点：
        1. 速度慢(调用函数前需要做“三件事”，函数执行完需要做“三件事”)
        2. 占用内存大
*/
