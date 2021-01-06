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
    int a[5]={1,2,3,4,5}; // 静态数组
    printf("请输入您想构造的数组长度：");
    scanf("%d",&len);
    int * p =(int *)malloc(sizeof(int)*len); // 利用malloc函数动态构造数组，p指向了前4个字节，其保存了第一个元素的地址
    for (i =0;i<len;i++)
    {

        scanf("%d",p+i); // p+i相当于 &p[i]
    }
    for (i=0;i<len;i++)
    {

        printf("%d\n",*(p+i));
    }
    free(p); // 把pArr所代表的动态分配的20个字节的内存释放
                    // 释放所构造的动态数组
    return 0;
}