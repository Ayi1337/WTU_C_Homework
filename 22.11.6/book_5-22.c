#include<stdio.h>                   //编译预处理文件，包含标准输入输出函数
int main()                          //主函数为：
{
    int i,n=1;                      //分别定义名为i,n的两个整型变量，并将1赋给变量n
    for(i=1;i<=100;i++)             //定义变量i等于1，当变量i小于等于100时开始执行循环体，完成循环后i加1
    {                               //循环体开端
        if(i%7!=0)                  //如果i取余7不等于0，重新开始下一次循环
            continue;               
        printf("%4d",i);            //使用输出函数输出“[i]”
        if(n++%5==0)printf("\n");   //如果n+1取余5等于0，输出回车
    }                               //循环体结尾
    return 0;                       //主函数返回0
}