/* @date: 2020-09-07 20:23:44
@功能:
    用递归求n!
@目的:
    了解递归的思想：要求n!，那你先告诉我（n-1）!;要求（n-1）!，那你先告诉我(n-2)!;....;1!为1，不需要你告诉了。
    再把以上获得信息综合，即可得n!
*/


# include <stdio.h>
long f(int n)
{
    if (n==1)
        return 1;
    else 
        return f(n-1)*n;
}
int main (void)
{
    int val;
    printf("您想求哪个数的阶乘：");
    scanf("%d",&val);
    printf("%d的阶乘是%ld\n",val,f(val));
    return 0;
}

/*@在VScode中的输出：
---------------------------------
您想求哪个数的阶乘：100
100的阶乘是0
---------------------------------
@总结：

*/
