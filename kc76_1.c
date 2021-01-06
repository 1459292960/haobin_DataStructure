/* @date: 2020-09-09 10:04:25
@功能:
    递归实现快速排序
@目的:

*/


# include <stdio.h>

void QuickSort(int * ,int ,int);
int Findpos1(int *,int ,int); // 升序
int Findpos2(int *,int ,int);// 倒序
int main (void)
{
    int i;
    int a[5]={-9,3,-55,100,2};
    QuickSort(a,0,4);
    for (i=0;i<5;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
// 经过一次排序，只能找到第一个元素的位置
void QuickSort(int * a,int low,int high)
{
    int pos;
    if(low<high)
    {

    pos = Findpos2(a,low,high); // 调用找位置程序
    QuickSort(a,low,pos-1);
    QuickSort(a,pos+1,high);

    }
}
// 按升序排序找到第一个元素的位置
int Findpos1(int * a,int low,int high)
{
    int val =a[low];
    while(low<high)
    {
        // 先移高位的位置
        while(low<high && val<=a[high] )
            high--;
        a[low]=a[high];
        while(low<high && a[low] <= val)
            low++;
        a[high]=a[low];


    }
    a[low]=val;
    return low; // 此时low =high
}
// 降序排列，找到所排序元素区间的第一个元素的位置
int Findpos2(int * a,int low,int high)
{
    int val =a[low];
    while(low<high)
    {
        // 先移高位的位置
        while(low<high && val>=a[high] ) // 保证val右边的都是比val小的数
            high--;
        a[low]=a[high];
        while(low<high && a[low] >= val)  // 保证val左边都是比val大的数
            low++;
        a[high]=a[low];


    }
    a[low]=val;
    return low;
}

/*@在VScode中的输出：
---------------------------------
100 3 2 -9 -55 
---------------------------------
@总结：

*/
