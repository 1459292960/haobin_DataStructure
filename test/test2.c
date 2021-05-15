#include <stdio.h>

void copy_string(char * from,char * to)
{   // from 和 to都是字符指针变量

    for(;*from != '\0';from++,to++)
    {
        *to = *from;
    }
    *to = '\0';
}
int main()
{
    char * a="I am a teacher.";
    char c[]="We are family!";
    char b[]="You are a student!";
    char *p = b;
    printf("string a = %s\nstring b = %s\n",a,b);
    copy_string(a,b); // b是指针常量
    printf("string a = %s\nstring b = %s\n",a,b);
    // int d[3]={1,2,3};
    // d++; // error，数组名代表数组第一个元素第一个字节的地址，不能修改。
    return 0;

}

