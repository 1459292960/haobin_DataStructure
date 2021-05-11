#include <stdio.h>

void copy_string(char * from,char * to)
{

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
    return 0;

}

