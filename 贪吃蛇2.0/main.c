/*1.打印地图，蛇，食物
2.蛇移动
3.蛇吃食物后加长
4.游戏判定*/



#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define H 40
#define W 40
#define snakesize 50
#define w 0
#define s 1
#define a 2
#define d 3
struct{int x;int y;}food;//食物
struct{int x;int y;}drug;//毒药
struct{int x[snakesize];int y[snakesize];int speed;int len;}snake;//蛇
int key=a;//初始方向
int feng=3;//分数
void start()
{
    gotoxy(20,20);
    printf("wsad为上下左右，请选择难度：简单3，困难2，地狱1\t$为食物，#为毒药\n");
    scanf("%d",&snake.speed);
}
void gotoxy(int x, int y)//定位光标位置到指定坐标
{HANDLE hout;
hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos = { x,y };
SetConsoleCursorPosition(hout, pos);}
void fengshu()//记录并显示分数
{
    gotoxy(42,40);
    printf("你的分数是%d",feng);}

void judge()//判断是否死亡
{
    if(snake.x[0]==0||snake.y[0]==0||snake.x[0]==40||snake.y[0]==40)
    {
        system("cls");
        gotoxy(20,20);
        printf("gameover\t你的分数是%d",feng);
        system("pause");

};

while(feng<1)
{
    system("cls");
        gotoxy(20,20);
        printf("gameover\t你的分数是%d",feng);
        system("pause");
}
for(int i=1;i<snake.len;i++)
{
    if(snake.x[0]==snake.x[i]&&snake.y[0]==snake.y[i])
        {
        system("cls");
        gotoxy(20,20);
        printf("gameover\t你的分数是%d",feng);
        system("pause");break;

};
}

}

void drawmap()//画出地图，蛇，食物
{
 srand((unsigned)time(NULL));
 food.x=rand()%(W-4)+2;
 food.y=rand()%(H-2)+1;
 gotoxy(food.x,food.y);
 printf("$");
//食物

 for(int i=0;i<=W;i++)
 {gotoxy(0,i);
 printf("■");
 gotoxy(W,i);
 printf("■");}
for(int i=0;i<=H;i+=2)
{
    gotoxy(i,0);
    printf("■");
    gotoxy(i,H);
    printf("■");
}//地图
snake.len=3;
snake.speed=1;
snake.x[0]=W/2;
snake.y[0]=H/2;
for(int k=1;k<snake.len;k++)
{snake.x[k]=snake.x[0]+k;
snake.y[k]=snake.y[0];}



}
void move()//蛇的移动
{ gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
  printf(" ");
for(int i=snake.len-1;i>0;i--)    //从尾巴开始，每一个点的位置等于它前面一个点的位置
    {
        snake.x[i]=snake.x[i-1];
        snake.y[i]=snake.y[i-1];
    }






    switch(key)
    {
    case w:
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
    gotoxy(snake.x[0],snake.y[0]);
    printf("@");

   }

void yingchang()
{CONSOLE_CURSOR_INFO cursor_info = {1, 0};
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);    //隐藏关标

}



void keya()//按键控制
{
    if(kbhit()!=0)          //如果有键盘输入
    {
        char in;
        while(!kbhit()==0)  //如果玩家输入了多个按键，以最后一个按键为准
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
void drawSnake()                //画蛇
{
    int i;
    for(i=0;i<snake.len;i++)
    {
        gotoxy(snake.x[0],snake.y[0]);        //移动关标到蛇的坐标
        printf("@");                    //在这个位置画蛇
    }
}
void food1()//食物再次生成
{
    if(snake.x[0]==food.x&&snake.y[0]==food.y)
    {srand((unsigned)time(NULL));
 food.x=rand()%(W-4)+2;
 food.y=rand()%(H-2)+1;
 gotoxy(food.x,food.y);
 printf("$");
snake.len++;
feng++;
    }
}
void drug1()//毒药再次生成
{
    if(snake.x[0]==drug.x&&snake.y[0]==drug.y)
    {srand((unsigned)time(NULL));
 drug.x=rand()%(W-4)+2;
 drug.y=rand()%(H-2)+1;
 gotoxy(drug.x,drug.y);
 printf("#");
gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
printf(" ");
snake.len--;
feng--;

    }
}
    int main()
{start();
system("cls");
drawmap();
Sleep(1000);
srand((unsigned)time(NULL));
 drug.x=rand()%(W-4)+2;
 drug.y=rand()%(H-2)+1;
 gotoxy(drug.x,drug.y);
 printf("#");//毒药
while(1)
    {yingchang();
        fengshu();
        drawSnake();
        move();
        Sleep(snake.speed*150);
        keya();
        food1();
        drug1();
    judge();

}

    return 0;}
