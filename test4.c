#include <stdio.h>
#include <string.h>
 
int main(void)
{
  char dest[7];
  char src[]="$GNGGAabcdefghijk";
    char * str1 = "$GNGGA";
  strncpy(dest,src,6);//注意一下这里假如改为5的话，可能会出现
                      //内存越界使得dest可能会占用其它模块的内存，从而导致错误发生;
  //strncpy(dest,src+5,4);//从第5个字符开始截取；
  dest[6]='\0';
  if(strcmp(dest,str1) == 0)
    printf("Yes\n");
  printf("dest: %s\n",dest);
  memset(dest,0,sizeof(dest));
  printf("dest:%s\n",dest);
return 0;
}