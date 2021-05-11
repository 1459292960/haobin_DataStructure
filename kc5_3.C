/* @date: 2020-08-28 19:27:21
@功能:

@目的:
确定一个一维数组需要传递两个参数：第一个元素的地址  数组的长度
*/


# include <stdio.h>

void ReArray(int * p, int len)
{  
    p[2]=-1; // p[2] == *(p+2) == *(a+2) == a[2]
    return ;
}
int main (void)
{
    int a[5]={1,2,3,4,5};
    ReArray(a,5);
    printf("%d\n",a[2]);
    return 0;
}

/*在VScode中的输出：
-1
总结：

*/
