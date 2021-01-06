/* @date: 2020-08-28 20:19:36
@功能:

@目的:
    熟悉结构体使用

*/


# include <stdio.h>
# include <string.h>

struct  Student
{
    int sid;
    char name[100];
    int age;
}; // 注意结尾有分号;

int main (void)
{
    struct Student st={99,"zhangsan",20};
    printf("%d %s %d\n",st.sid,st.name,st.age);

    st.age=23;
    st.sid=80;
    strcpy(st.name,"lisi"); // 给字符串赋值要通过strcpy方法
    printf("%d %s %d\n",st.sid,st.name,st.age);
    return 0;
}

/*在VScode中的输出：

总结：
结构体是类的过渡
结构体中只能定义属性，不能定义/调用 函数
*/
