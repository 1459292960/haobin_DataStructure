#include <stdio.h>

void sort1(int * a,int len);
void sort2(int * a,int len);
void show_arr(int * a,int len);

int main(void){
    int a[]={7,2,90,-1,6};
    int b[5];
    for(int i = 0; i < 5; i++){
        b[i] = a[i];
    }
    show_arr(a,5);
    show_arr(b,5);
    int len;
    printf("len = %ld\n",sizeof(a)/sizeof(a[0]));
    sort1(a,5);
    sort2(b,5);
    show_arr(a,5);
    show_arr(b,5);
    return 0;
}
// 相邻两个元素进行比较，大的放后面，第一次循环完，最大的放在最后面
void sort1(int * a,int len){
    // int len = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < len-1;i++){
        for(int j = 0; j < len-i-1; j++){
            if(a[j] > a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    return;
}
// 第一个依次与后面的元素进行比较，把最小的先放在第一个
void sort2(int * a,int len){
    for(int i = 0; i < len -1; i++){
        for(int j = i+1; j < len; j++){
            if(a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    return ; 
}

void show_arr(int * a,int len){
    // int len = sizeof(a)/sizeof(a[0]); // sizeof()求变量或数据类型所占的字节数，对于数组来说，没有\0结束，所以这样刚好求出来就是它的长度
    // printf("show len = %d\n",len);
    for(int i = 0; i < len; i++){
        i && printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    return ;
}