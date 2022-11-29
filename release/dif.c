#include<stdio.h>
#include<stdlib.h>

#define PLAYER 10
#define TEACHER 7

void menu();
void in_name();
void sub_menu_1();
void sub_menu_2();
void sub_menu_3();
void sub_menu_4();
void sub_menu_5();

struct players
{
	int player_number;
	char player_name[PLAYER];
	char player_gender;
	int player_score[TEACHER];
	float player_ave;
    int player_rank;
}player[PLAYER];

int main()
{
	menu();
}  

void menu()
{
	int choice;
	printf("*******************请选择操作代码***********************\n");
	printf("*    1.输入分数\n");
	printf("*    2.计算平均分\n");
	printf("*    3.显示选手最后得分\n");
	printf("*    4.删除无效选手成绩\n");
	printf("*    5.显示选手排名次序\n");
	printf("*    6.退出系统\n");
    printf("*    7.name\n");
	printf("*********************************************************\n");
	scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        sub_menu_1();
        break;

    case 2:
        sub_menu_2();
        break;

    case 3:
        sub_menu_3();
        break;

    case 4:
        sub_menu_4();
        break;

    case 5:
        sub_menu_5();
        break;

    case 6:
        exit(0);

    case 7:
        in_name();
        break;
    
    default:
        printf("error");
        break;
    }
}

void in_name()
{
    for (int i = 0; i < PLAYER; i++)
    {   
        printf("请输入选手%d的姓名为和性别(男性请输入M,女性输入F)：\n",i+1);
        scanf("%s %s",&player[i].player_name,&player[i].player_gender);
        player[i].player_number=i+1;
    }
    menu();
}

void sub_menu_1()
{
    printf("现在请评委打分\n");
    for (int i = 0; i < PLAYER; i++)
    {
        for (int x = 0; x < TEACHER; x++)
        {
            scanf("%d",&player[i].player_score[x]);
            printf("评委%d给参赛选手%d出的分数为：%d\n",x+1,i+1,player[i].player_score[x]);
        }
        printf("参赛选手%d成绩输入完毕\n",i+1);
    }
    printf("全部%d名参赛选手成绩输入完毕\n",PLAYER);
    menu();
}

void sub_menu_2()
{
    float sum;
    printf("现在进入计算平均分环节：\n");
    int i,x,j,temp;
    for(i=0;i<PLAYER;i++)
    {
        for(x=0;x<PLAYER;x++)
        {
            for(j=0;j<TEACHER-1;j++)
            {
                if(player[x].player_score[j]>player[x].player_score[j+1])
                {
                    temp=player[x].player_score[j+1];
                    player[x].player_score[j+1]=player[x].player_score[j];
                    player[x].player_score[j]=temp;
                }
            }
        }
    }
    for ( i = 0; i < PLAYER; i++)
    {
        sum=0;
        printf("第%2d名选手的分数为：",i+1);
        for ( x = 0; x < TEACHER; x++)
        {
            printf("%3d",player[i].player_score[x]);
            sum+=player[i].player_score[x];
        }
        player[i].player_ave=(sum-player[i].player_score[0]-player[i].player_score[6])/5.0;
        printf("\t去除最低分%d与最高分%d后最后得分为：%.2f",player[i].player_score[0],player[i].player_score[6],player[i].player_ave);
        printf("\n");
    }
    menu();
}

void sub_menu_3()
{
    for (int i = 0; i < PLAYER; i++)
    {
        printf("%2d号选手%10s,性别%c,最后得分为%.2f\n",player[i].player_number,player[i].player_name,player[i].player_gender,player[i].player_ave);
    }
    menu();
}

void sub_menu_4()
{
    for (int i = 0; i < PLAYER; i++)
    {
        for (int x = 0; x < TEACHER; x++)
        {
            if (player[i].player_ave<6.0||player[i].player_score[x]==0)
            {
                printf("%d号选手成绩无效，被删除\n",player[i].player_number);
                player[i].player_ave=0;
            }
            continue;
        }
        printf("筛选成绩完成");
    }
    menu();
}

void sub_menu_5()
{
    int rank_lost=0,rank=1;
    for (int i = 0; i < PLAYER; i++)
    {
        printf("外循环");
        for (int x = 0; x < PLAYER; x++)
        {
            printf("内循环");
            if (player[i].player_ave<=player[x].player_ave)
            {
                rank_lost++;
            }
            continue;
        }
        player[i].player_rank=rank_lost;
        rank_lost=0;
    }
    for (int i = 0; i < PLAYER; i++)
    {   
        printf("二外循环");
        if (player[i].player_rank==rank)
        {
            printf("第%d名为%2d号选手%10s,性别%c,最后得分为%.2f\n",player[i].player_rank,player[i].player_number,player[i].player_name,player[i].player_gender,player[i].player_ave);
            i = 0;
        }
        rank++;
    }
    menu();
}
