/*
1.��ʼ����ͼ���ߣ�ʳ��
2���ߵ��ƶ���ͷ�����壬β�ͣ�
3.�������������
4.ʳ����ٴβ�������ӡ��
5.�ж�����
*/
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define a 1
#define d 2
#define w 3
#define s 4
struct{int x[50];int y[50];int len;}snake;
struct{int x;int y;}food;
int key=a;
void gotoxy(int x, int y)//��λ���λ�õ�ָ������
{HANDLE hout;
hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos = { x,y };
SetConsoleCursorPosition(hout, pos);}
void init()//��ʼ��
{for(int i=0;i<40;i++)
{
    gotoxy(0,i);
    printf("*");
    gotoxy(40,i);
    printf("*");
}
for(int i=0;i<40;i++)
{
    gotoxy(i,0);
    printf("*");
    gotoxy(i,40);
    printf("*");
}//��ӡ��ͼ
snake.x[0]=20;snake.y[0]=20;
snake.x[1]=21;snake.y[1]=20;
snake.x[2]=22;snake.y[2]=20;
snake.len=3;//��ʼ����
srand((unsigned)time(NULL));
food.x=rand()%38+1;
food.y=rand()%38+1;
gotoxy(food.x,food.y);
printf("$");
}
void move()//�ߵ��ƶ�
{
    gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
    printf(" ");
    for(int i=snake.len-1;i>0;i--)
    {
        snake.x[i]=snake.x[i-1];
        snake.y[i]=snake.y[i-1];
    }
    switch(key)
    {case w:
        snake.y[0]--;
        break;
    case s:
        snake.y[0]++;
        break;
    case a:
        snake.x[0]--;
        break;
    case d:
        snake.x[0]++;
        break;
    }

}
void drawsnake()//���»���
{
    for(int i=0; i<snake.len;i++)
    {
        gotoxy(snake.x[i],snake.y[i]);
        printf("@");
    }
}
void keyboard()
{ if(kbhit()!=0)          //����м�������
    {
        char in;
         in=getch();
        switch(in)
        {
        case 'w':
        case 'W':
            if(key!=s)         //������ͷ�ɡ�������
                key=w;
            break;
        case 's':
        case 'S':
            if(key!=w)
                key=s;
            break;
        case 'a':
        case 'A':
            if(key!=d)
                key=a;
            break;
        case 'd':
        case 'D':
            if(key!=a)
                key=d;
            break;
        }
    }

}

void newfood()//��ʳ������ɺ��ߵı䳤
{
    if(snake.x[0]==food.x&&snake.y[0]==food.y)
    {srand((unsigned)time(NULL));
food.x=rand()%38+1;
food.y=rand()%38+1;
gotoxy(food.x,food.y);
printf("$");
snake.len++;

    }
}
void yingchang()//���عر�,�����������������
{CONSOLE_CURSOR_INFO cursor_info = {1, 0};
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}
void judge()
{
    if(snake.x[0]==0||snake.x[0]==40||snake.y[0]==0||snake.y[0]==40)
    {
        system("cls");
        printf("gameover,��ķ�����%d",snake.len);
        system("pause");
    }
    for(int i=1;i<snake.len;i++)
{
    if(snake.x[0]==snake.x[i]&&snake.y[0]==snake.y[i])
        {
        system("cls");
        gotoxy(20,20);
        printf("gameover\t��ķ�����%d",snake.len);
        system("pause");
}}}
int main()
{
    init();
    while(1)
    {
    move();
    drawsnake();
    Sleep(500);
    keyboard();
    newfood();
    judge();
    yingchang();
    }
    return 0;
}
