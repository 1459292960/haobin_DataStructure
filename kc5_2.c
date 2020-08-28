/* @date: 2020-08-28 19:13:22
@功能:

@目的:
一维数组名的概念
*/


# include <stdio.h>

int main (void)
{
    int a[5]={1,2,3,4,5};

    printf("%d %d %d %d\n",a[3],*(a+3),*(3+a),3[a]);// 一维数组名代表一维数组第一个元素的地址
    return 0;
}

/*在VScode中的输出：
4 4 4 4
总结：

*/
