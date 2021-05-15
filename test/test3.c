#include <stdio.h>
#include "string.h"

int main(void)
{
    char * a = "I am a teacher.";
    char c[] = "We are Family!";
    char b[50];
    strcat(b,a);
    printf("string b = %s\n",b);
    strcat(b,c);
    printf("string b = %s\n",b);
    return 0;
}