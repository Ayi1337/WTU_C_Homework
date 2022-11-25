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
void clean_screen();

struct players
{
	int player_number;
	char player_name[PLAYER];
	char player_gender;
	int player_score[PLAYER];
	float player_ave;
}player[PLAYER]={
             {1,"��С��1",'M',0,0,0,0,0,0,0,0,0,0},
             {2,"��С��2",'M',10,2,6,4,7,8,5,1,4,7},
             {3,"��С��3",'M',10,3,6,4,7,8,5,1,4,7},
             {4,"��С��4",'M',10,4,6,4,7,8,5,1,4,7},
             {5,"��С��5",'M',10,5,6,4,1,8,5,1,4,7},
             {6,"��С��6",'M',10,6,6,4,7,8,5,1,4,7},
             {7,"��С��7",'M',10,7,6,1,7,8,5,1,4,7},
             {8,"��С��8",'M',10,8,6,4,7,8,5,1,4,7},
             {9,"��С��9",'M',10,0,6,4,7,8,5,1,4,7},
             {10,"��С��0",'M',10,0,6,4,7,8,5,1,4,7}
             },temp;
int main()
{
	menu();
}  

void menu()
{
	int choice;
	printf("*******************��ѡ���������***********************\n");
    printf("*    1.¼���������Ա�\n");
	printf("*    2.�������\n");
	printf("*    3.����ƽ����\n");
	printf("*    4.��ʾѡ�����÷�\n");
	printf("*    5.ɾ����Чѡ�ֳɼ�\n");
	printf("*    6.��ʾѡ����������\n");
	printf("*    7.�˳�ϵͳ\n");
	printf("*********************************************************\n");
	scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        in_name();
        break;
    
    case 2:
        sub_menu_1();
        break;

    case 3:
        sub_menu_2();
        break;

    case 4:
        sub_menu_3();
        break;

    case 5:
        sub_menu_4();
        break;

    case 6:
        sub_menu_5();
        break;

    case 7:
        exit(0);
    
    default:
        printf("�������벻�Ϸ���������\n");
        menu();
    }
}

void in_name()
{
    clean_screen();
    for (int i = 0; i < PLAYER; i++)
    {   
        printf("������ѡ��%d������Ϊ���Ա�(����������M,Ů������F)��\n",i+1);
        scanf("%s %s",&player[i].player_name,&player[i].player_gender);
        player[i].player_number=i+1;
    }
    menu();
}

void sub_menu_1()
{
    clean_screen();
    printf("��������ί���\n");
    for (int i = 0; i < PLAYER; i++)
    {
        for (int x = 0; x < TEACHER; x++)
        {
            scanf("%d",&player[i].player_score[x]);
            if (player[i].player_score[x]>10||player[i].player_score[x]<0)
            {
                printf("���벻�Ϸ���������\n");
                x--;
                continue;
            }
            printf("��ί%d������ѡ��%d���ķ���Ϊ��%d\n",x+1,i+1,player[i].player_score[x]);
        }
        printf("����ѡ��%d�ɼ��������\n",i+1);
    }
    printf("ȫ��%d������ѡ�ֳɼ��������\n",PLAYER);
    menu();
}

void sub_menu_2()
{
    clean_screen();
    float sum;
    printf("���ڽ������ƽ���ֻ��ڣ�\n");
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
        printf("��%2d��ѡ�ֵķ���Ϊ��",i+1);
        for ( x = 0; x < TEACHER; x++)
        {
            printf("%3d",player[i].player_score[x]);
            sum+=player[i].player_score[x];
        }
        player[i].player_ave=(sum-player[i].player_score[0]-player[i].player_score[6])/5.0;
        printf("\tȥ����ͷ�%d����߷�%d�����÷�Ϊ��%.2f",player[i].player_score[0],player[i].player_score[6],player[i].player_ave);
        printf("\n");
    }
    menu();
}

void sub_menu_3()
{
    clean_screen();
    for (int i = 0; i < PLAYER; i++)
    {
        printf("%2d��ѡ��%10s,�Ա�%c,���÷�Ϊ%.2f\n",player[i].player_number,player[i].player_name,player[i].player_gender,player[i].player_ave);
    }
    menu();
}

void sub_menu_4()
{
    clean_screen();
    for (int i = 0; i < PLAYER; i++)
    {
        if(player[i].player_ave<6.0)
        {
            printf("%d��ѡ��������һ��0�ֳɼ���Ч����ɾ��\n",player[i].player_number);
            player[i].player_ave=0;
            continue;
        }
        for (int x = 0; x < TEACHER; x++)
        {
            if (player[i].player_score[x]==0)
            {
                printf("%d��ѡ�ֳɼ���Ч����ɾ��\n",player[i].player_number);
                player[i].player_ave=0;
                break;
            }
        }
    }
    printf("�ɼ�ɸѡ���\n\n");
    menu();
}

void sub_menu_5()
{
    clean_screen();
    for (int i = 0; i < PLAYER-1; i++)
    {
        for (int j = i+1; j < PLAYER; j++)
        {
            if (player[i].player_ave < player[j].player_ave)
            {
                temp=player[i];
                player[i]=player[j];
                player[j]=temp;
            }
        }
    }
    for ( int i = 0; i < PLAYER; i++)
    {
        if(player[i].player_ave==0)
        {
            printf("%2d��ѡ��%10s,�Ա�%c,���÷�%.2f,������\n",player[i].player_number,player[i].player_name,player[i].player_gender,player[i].player_ave);
        }else
            printf("��%2d��Ϊ%2d��ѡ��%10s,�Ա�%c,���÷�Ϊ%.2f\n",i+1,player[i].player_number,player[i].player_name,player[i].player_gender,player[i].player_ave);
    }
    menu();
}

void clean_screen()
{
    system("cls");
}