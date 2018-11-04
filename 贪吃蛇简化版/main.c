/*
1.初始化地图，蛇，食物
2，蛇的移动（头，身体，尾巴）
3.按键输入与接收
4.食物的再次产生，打印蛇
5.判断死亡
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
void gotoxy(int x, int y)//定位光标位置到指定坐标
{HANDLE hout;
hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos = { x,y };
SetConsoleCursorPosition(hout, pos);}
void init()//初始化
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
}//打印地图
snake.x[0]=20;snake.y[0]=20;
snake.x[1]=21;snake.y[1]=20;
snake.x[2]=22;snake.y[2]=20;
snake.len=3;//初始化蛇
srand((unsigned)time(NULL));
food.x=rand()%38+1;
food.y=rand()%38+1;
gotoxy(food.x,food.y);
printf("$");
}
void move()//蛇的移动
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
void drawsnake()//重新画蛇
{
    for(int i=0; i<snake.len;i++)
    {
        gotoxy(snake.x[i],snake.y[i]);
        printf("@");
    }
}
void keyboard()
{ if(kbhit()!=0)          //如果有键盘输入
    {
        char in;
         in=getch();
        switch(in)
        {
        case 'w':
        case 'W':
            if(key!=s)         //不能缩头吧。。。。
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

void newfood()//新食物的生成和蛇的变长
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
void yingchang()//隐藏关标,加了这个函数更美观
{CONSOLE_CURSOR_INFO cursor_info = {1, 0};
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}
void judge()
{
    if(snake.x[0]==0||snake.x[0]==40||snake.y[0]==0||snake.y[0]==40)
    {
        system("cls");
        printf("gameover,你的分数是%d",snake.len);
        system("pause");
    }
    for(int i=1;i<snake.len;i++)
{
    if(snake.x[0]==snake.x[i]&&snake.y[0]==snake.y[i])
        {
        system("cls");
        gotoxy(20,20);
        printf("gameover\t你的分数是%d",snake.len);
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
