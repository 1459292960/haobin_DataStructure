/*@date:2021-04-29

@功能:
    结构变量所占用的内存大小需要用到内存对齐的知识。
@目的:
    
*/


#include<stdio.h>
/*  以单个元素占字节最大的为内存对齐
    A占4个字节
    B占一个字节
    C占8个字节，
    看链接https://zhidao.baidu.com/question/183477298.html
*/
typedef struct{
    int A;
    char B;
    double C;
}yy;
typedef struct{
    int A;
    double B;
    char C;

}xx;
int main(void){
    printf("the xx struct size is %ld\n",sizeof(xx));
    printf("the yy struct size is %ld\n",sizeof(yy));
    return 0;
}