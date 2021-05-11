/* @date: 2021-05-11 20:35:39
    可伸缩数组
@功能:

@目的:

*/


#include<stdio.h>
#include<malloc.h>

typedef struct arr{
    int a;
    int b[];
}ARR,* PARR;

int main(void){
    int a = (int)3.2;
    // 后面申请的两个int数据（8个字节）是给int b[]数组申请的
    PARR pArr = (PARR)malloc(sizeof(ARR)+2*sizeof(int)); // 等式右边不加PARR强制类型转换，靠等式左边的PARR类型指针也可完成强制类型转换
    pArr->b[0] = 2;
    pArr->b[1] = 7;

    printf("%ld\n",sizeof(ARR));
    printf("%d\n",pArr->b[0]);
    return 0;
}