/*1.��ӡ��ͼ���ߣ�ʳ��
2.���ƶ�
3.�߳�ʳ���ӳ�
4.��Ϸ�ж�*/



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
struct{int x;int y;}food;//ʳ��
struct{int x;int y;}drug;//��ҩ
struct{int x[snakesize];int y[snakesize];int speed;int len;}snake;//��
int key=a;//��ʼ����
int feng=3;//����
void start()
{
    gotoxy(20,20);
    printf("wsadΪ�������ң���ѡ���Ѷȣ���3������2������1\t$Ϊʳ�#Ϊ��ҩ\n");
    scanf("%d",&snake.speed);
}
void gotoxy(int x, int y)//��λ���λ�õ�ָ������
{HANDLE hout;
hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos = { x,y };
SetConsoleCursorPosition(hout, pos);}
void fengshu()//��¼����ʾ����
{
    gotoxy(42,40);
    printf("��ķ�����%d",feng);}

void judge()//�ж��Ƿ�����
{
    if(snake.x[0]==0||snake.y[0]==0||snake.x[0]==40||snake.y[0]==40)
    {
        system("cls");
        gotoxy(20,20);
        printf("gameover\t��ķ�����%d",feng);
        system("pause");

};

while(feng<1)
{
    system("cls");
        gotoxy(20,20);
        printf("gameover\t��ķ�����%d",feng);
        system("pause");
}
for(int i=1;i<snake.len;i++)
{
    if(snake.x[0]==snake.x[i]&&snake.y[0]==snake.y[i])
        {
        system("cls");
        gotoxy(20,20);
        printf("gameover\t��ķ�����%d",feng);
        system("pause");break;

};
}

}

void drawmap()//������ͼ���ߣ�ʳ��
{
 srand((unsigned)time(NULL));
 food.x=rand()%(W-4)+2;
 food.y=rand()%(H-2)+1;
 gotoxy(food.x,food.y);
 printf("$");
//ʳ��

 for(int i=0;i<=W;i++)
 {gotoxy(0,i);
 printf("��");
 gotoxy(W,i);
 printf("��");}
for(int i=0;i<=H;i+=2)
{
    gotoxy(i,0);
    printf("��");
    gotoxy(i,H);
    printf("��");
}//��ͼ
snake.len=3;
snake.speed=1;
snake.x[0]=W/2;
snake.y[0]=H/2;
for(int k=1;k<snake.len;k++)
{snake.x[k]=snake.x[0]+k;
snake.y[k]=snake.y[0];}



}
void move()//�ߵ��ƶ�
{ gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
  printf(" ");
for(int i=snake.len-1;i>0;i--)    //��β�Ϳ�ʼ��ÿһ�����λ�õ�����ǰ��һ�����λ��
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
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);    //���عر�

}



void keya()//��������
{
    if(kbhit()!=0)          //����м�������
    {
        char in;
        while(!kbhit()==0)  //�����������˶�������������һ������Ϊ׼
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
void drawSnake()                //����
{
    int i;
    for(i=0;i<snake.len;i++)
    {
        gotoxy(snake.x[0],snake.y[0]);        //�ƶ��ر굽�ߵ�����
        printf("@");                    //�����λ�û���
    }
}
void food1()//ʳ���ٴ�����
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
void drug1()//��ҩ�ٴ�����
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
 printf("#");//��ҩ
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
