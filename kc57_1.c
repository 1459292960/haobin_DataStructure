/* @date: 2020-09-08 14:49:25
@功能:
    解决汉诺塔问题
@目的:
    递归思想：n规模的问题的解决依赖于 n-1问题的解决而解决
*/


# include <stdio.h>
// 汉诺塔函数功能：将A所代表的柱子上的n个盘子，借助B所代表的柱子，移到C所代表的柱子上
void hannuota(int n,char A,char B,char C)
{
    if (1 ==n)
        printf("将编号为%d的盘子从%c的柱子直接移到%c的柱子\n",n,A,C);
    else
    {
        hannuota(n-1,A,C,B); // 将A所代表的柱子上的n-1个盘子，借助C所代表的柱子，移动到B所代表的柱子上
        printf("将编号为%d的盘子从%c的柱子直接移到%c的柱子\n",n,A,C);
        hannuota(n-1,B,A,C); // 将B所代表的柱子上的n-1个盘子，借助A所代表的柱子，移动到C所代表的柱子上
    }
    
} 
int  main (void)
{
    char A;
    char B;
    char C;
    int n;
    printf("请输入您想移动的盘子数：");
    scanf("%d",&n);
    hannuota(n,'A','B','C');
    return 0;
}