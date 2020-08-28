/* @date: 2020-08-28 21:14:45
@功能:

@目的:
动态分配内存
*/


# include <stdio.h>
# include <malloc.h>

int main(void)
{
    int len;
    int i;
    printf("请输入您想构造的数组长度：");
    scanf("%d",&len);
    int * p =(int *)malloc(sizeof(int)*len); // 利用malloc函数动态构造数组
    for (i =0;i<len;i++)
    {

        scanf("%d",p+i); // p+i相当于 &p[i]
    }
    for (i=0;i<len;i++)
    {

        printf("%d\n",*(p+i));
    }
    free(p); // 释放所构造的动态数组
    return 0;
}