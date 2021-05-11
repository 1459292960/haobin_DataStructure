#include <stdio.h>
#include "math.h"
char get(unsigned char  x)
{

    char y;
    char fan_ma;
    y = x>>7;
    fan_ma = x^(-y);
    if(y)
         return -(fan_ma+y);
    else
    {
        return (fan_ma+y);
    }
    
}

short  get_yuanma(unsigned short x)
{

    short   y;
    short  fan_ma;
    y = x>>15;
    fan_ma = x^(-y);
    if(y)
         return -(fan_ma+y);
    else
    {
        return (fan_ma+y);
    }
    
}
int main (void)
{
    unsigned char i = 0xD1; 
    unsigned char k = 0x12;
    unsigned short p = k<<8|i;
    printf("%x\n",p);
    unsigned short j = 0xFfd1;
    char y;
    char fan_ma;
     char yuan_ma;
    y = (i>>7);
    printf("函数求得 = %d\n",get(i));
    printf("16位求原码 = %d\n",get_yuanma(j));
    printf("补码 = %x\n",i);
    printf("%d\n",y);
    printf("%x\n",y);
    printf("%x\n",0x01|(y<<7));
    fan_ma = i^(-y);
    printf("%d\n",fan_ma); //取反加1
    printf("反码 = %x\n",fan_ma);
    printf("反码+1 = %x\n",(fan_ma+y)|(y<<7));
    yuan_ma = (fan_ma+y)|(y<<7);
        printf("反码+1 = %x\n",yuan_ma);
        printf("%d\n",yuan_ma);
    printf("%d\n",sizeof(char));
    printf("%d\n",sizeof(short));
    
   if(y)
   {
       yuan_ma =-(fan_ma+y);
        printf("原码 = %x\n",yuan_ma);
        printf("%d\n",yuan_ma);
       return yuan_ma;
   }
   else
   {
       yuan_ma = (fan_ma+y);
        printf("原码 = %x\n",yuan_ma);
        printf("%d\n",yuan_ma);
       return yuan_ma;
   }
   
    // yuan_ma = (fan_ma-y)|(y<<7);
    // printf("%d\n",yuan_ma);
    // printf("原码 = %x\n",yuan_ma);
    // if y
    // yuan_ma = 
    // printf


   //  printf("%\n",get(i));


   //  return 0;
}