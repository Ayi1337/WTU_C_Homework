//选择法排序
#include<stdio.h>                           //编译预处理文件，包含标准输入输出函数
int main()                                  //主函数为：
{
    int i,j,t,a[10];                        //分别定义名为i,j,t的整型变量以及含有10个元素的整型数组a
    printf("请输入10个整数");                //使用输出函数输出“请输入10个整数” 
    for(j=0;j<10;j++)                       //定义变量j为0，当变量j小于10时开始执行循环体，完成循环后j加1
        scanf("%d",&a[j]);                  //使用输入函数将数据保存进数组a[j]，循环体结束
    printf("\n");                           //使用输出函数输出回车
    for(i=0;i<9;i++)                        //定义变量i为0，当变量i小于9时开始执行循环体，完成循环后i加1
        for(j=i+1;j<10;j++)                 //定义变量j等于i+1，当变量j小于10时开始执行循环体，完成循环后j加1
            if(a[i]>a[j])                   //如果数组a[i]内的值大于数组a[j]内的值时执行
            {                               //第二层循环体开端
                t=a[i];                     //将数组a[i]内的值赋给变量t
                a[i]=a[j];                  //将数组a[j]内的值赋给数组a[i]
                a[j]=t;                     //将变量t的值赋给数组a[j]
            }                               //第二层循环体结尾
    printf("排序之后:\n");                   //使用输出函数输出“排序之后:”并回车 
    for(j=0;j<10;j++)                       //定义变量j等于0，当变量j小于10时开始执行循环体，完成循环后j+1
        printf("%4d",a[j]);                 //使用输出函数输出“a[j]的值” 
    return 0;                               //主函数返回0
}