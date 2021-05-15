#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char * my_strdup(char * s1)
{
    char * str;
    size_t size = strlen(s1)+1;
    str = malloc(size);
    if(str)
    {
        memcpy(str,s1,size);
    }
    return str;

}

static char* strsplit(char** stringp, const char* delim)
{
    char * start;
	start = *stringp;
    char * p;

    p = (start != NULL) ? strpbrk(start, delim) : NULL;

    if (p == NULL)
    {
        *stringp = NULL;
    }
    else
    {
        *p = '\0';
        *stringp = p + 1;
    }

    return start;
}
int main()
{

    char src[] = "$GNRMC,013300.00,A,2240.84105,N,11402.70763,E,0.007,,220319,,,D*69\r\n"
                        "$GNVTG,,T,,M,0.007,N,0.014,K,D*3A\r\n"
                        "$GNGGA,013300.00,2240.84105,N,11402.70763,E,2,12,0.59,70.5,M,-2.5,M,,0000*68\r\n"
                        "$GNGSA,A,3,10,12,14,20,25,31,32,26,29,40,41,22,1.09,0.59,0.91*1F\r\n"
                        "$GNGSA,A,3,74,70,73,80,69,,,,,,,,1.09,0.59,0.91*17\r\n"
                        "$GPGSV,4,1,16,01,00,300,,10,56,178,51,12,12,038,38,14,47,345,48*79\r\n"
                        "$GPGSV,4,2,16,16,00,207,,18,06,275,30,20,28,165,43,22,10,319,43*76\r\n"
                        "$GPGSV,4,3,16,25,46,050,47,26,29,205,44,29,13,108,45,31,50,296,52*7E\r\n"
                        "$GPGSV,4,4,16,32,56,010,52,40,20,257,40,41,46,237,48,42,46,123,42*77\r\n"
                        "$GLGSV,2,1,06,69,27,136,49,70,76,057,50,71,34,338,50,73,64,276,55*6B\r\n"
                        "$GLGSV,2,2,06,74,24,231,46,80,35,019,46*60\r\n"
                        "$GNGLL,2240.84105,N,11402.70763,E,013300.00,A,D*7C\r\n";
	
    printf("之前地址：\n");
    printf("%p\n",src);
    
    char *result  = NULL;
    result = my_strdup(src);
    printf("%ld\n",sizeof(char));
    printf("字符串拷贝后地址：\n");
    printf("%p\n",result);
  //  printf("%s\n",result);
    char * p = strsplit(&result,",");
    printf("%s\n",p);
    //free(result);
    return 0;
}