#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
using namespace std;
int m[10001][21]={
{-1,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{-1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{-1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{-1,19,0,0,0,0,0,1,1,1,0,0,12,0,0,0,0,0,0,0,0},
{-1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
{-1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,4,0,0,0,0},
{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{-1,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{-1,0,0,0,2,2,0,0,3,3,0,0,6,6,0,0,0,0,0,0,0},
{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
{-1,15,0,0,0,0,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0},
{-1,0,0,0,0,0,0,0,0,0,0,0,0,16,17,0,0,0,0,0,0},
{-1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{-1,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{-1,0,0,0,1,1,0,0,2,2,0,0,0,1,1,1,0,0,0,0,0},
};
int X,Y,dx,dy,tX,zX,zY,Sstar,Sboom,Win;
int Ee,Fen,RR,Slep,K,S,Er,Ice,Fang,Can;
int Ta,Zha,Bai,Yin,Su,U,TT,Ty,sy;
void Color(int a)
{
    a+=Bai*20;
    if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    if(a==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a%20==9) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a==10) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
    else if(a>20) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}
void SetPos(int x,int y)
{
    COORD pos;
    pos.X=y*2-1,pos.Y=26-x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Star();
void Wo(int x)
{
    SetPos(X-K,Y),cout<<"  "; //�����һ�β�Ӱ
    if(Can!=0) {SetPos(X-K,Y),Color(10),cout<<"��";int R=rand()%5;if(R==0&&Y<20) Y++;if(R==1&&Y>1) Y--;}//�˷� 
    if((m[X][Y]==1||m[X][Y]==7)&&Ta==0) X++; //���ϰ׿� 
    if(X<=0) X=dx,Y=dy;  //���� 
    if(X-K>23) tX=0,X=K+23;  //�߶�����
    if(tX!=0&&Ta==0) tX--,X+=2;  //���� 
    if(Ta!=0) {tX=0;if(m[X-1][Y]==0||m[X-1][Y]==4||m[X-1][Y]==5||(m[X-1][Y]>=9&&m[X-1][Y]<=18)) m[X-1][Y]=7;} //��Ь��· 
    if(m[X][Y]==6) X--;  //���ο� 
    if(m[X+1][Y]==6){tX=0;m[X+1][Y]=7;if(m[X+1][Y-1]==6) m[X+1][Y-1]=7;if(m[X+1][Y+1]==6) m[X+1][Y+1]=7;Fen+=2;} //���ο� 
    if(m[X-1][Y]==6){tX=0;m[X-1][Y]=7;if(m[X-1][Y-1]==6) m[X-1][Y-1]=7;if(m[X-1][Y+1]==6) m[X+1][Y+1]=7;Fen+=2;} //���ο� 
    if(m[X][Y+1]==6){tX=0;m[X][Y+1]=m[X][Y+2]=7;Fen+=2;} if(m[X][Y-1]==6){tX=0;m[X][Y-1]=m[X][Y-2]=7;Fen+=2;} //���ο� 
    if(m[X-1][Y]==0||m[X-1][Y]==4||m[X-1][Y]==5||(m[X-1][Y]>=9&&m[X-1][Y]<=20)) {X--;} //���� 
    if(m[X][Y]==4) Fen+=5,m[X][Y]=5,dx=X,dy=Y; //����� 
    if(m[X][Y]==16) m[X][Y]=0,Sstar++,Star(),SetPos(X-K,Y),cout<<"  ";if(m[X+1][Y]==16) m[X+1][Y]=0,Sstar++,Star(),SetPos(X-K+1,Y),cout<<"  "; //����
    if(m[X-1][Y]==1||m[X-1][Y]==2||m[X-1][Y]==3||m[X-1][Y]==7) tX=Er=0; //��Ծ�������� 
    if(m[X-1][Y]==2||m[X][Y]==2||Ta!=0) tX+=5; //������ 
    if(m[X-1][Y]==10) m[X-1][Y]=3,Sboom++;if(m[X][Y]==10) m[X][Y]=3,X++,Sboom++; //����ը���� 
    if(m[X-1][Y]==3||m[X][Y]==3) //ը���� 
    {
        if(Zha==0)
        {
            Zha++;
            SetPos(X+1-K,Y-1),Color(5),cout<<"��";SetPos(X+1-K,Y+1),Color(5),cout<<"��";SetPos(X+1-K,Y),Color(5),cout<<"��";SetPos(X-1-K,Y-1),Color(5),cout<<"��";
            SetPos(X-1-K,Y+1),Color(5),cout<<"��";SetPos(X-1-K,Y),Color(5),cout<<"��";SetPos(X-K,Y-1),Color(5),cout<<"��";SetPos(X-K,Y+1),Color(5),cout<<"��";
            SetPos(X-K,Y),Color(5),cout<<"��";Sleep(300);SetPos(X+1-K,Y-1),Color(5),cout<<"  ";
            SetPos(X+1-K,Y+1),Color(5),cout<<"  ";SetPos(X+1-K,Y),Color(5),cout<<"  ";SetPos(X-1-K,Y-1),Color(5),cout<<"  ";SetPos(X-1-K,Y+1),Color(5),cout<<"  ";
            SetPos(X-1-K,Y),Color(5),cout<<"  ";SetPos(X-K,Y-1),Color(5),cout<<"  ";SetPos(X-K,Y+1),Color(5),cout<<"  ";SetPos(X-K,Y),Color(5),cout<<"  "; //����
        }if(m[X][Y]==3) X++;
        if(Fang==0) X=dx,Y=dy,Fen-=5; //����
    }else Zha=0;
    if(x==3) {int U=rand()%10;SetPos(X-K,Y);if(U==0) Color(6),cout<<"��";} //���� 
    else if(Fang!=0) SetPos(X-K,Y),Color(2),cout<<"��"; //����
    else if(Can!=0) SetPos(X-K,Y),Color(4),cout<<"��"; //�˷� 
    else if(x==2) SetPos(X-K,Y),Color(5),cout<<"��"; //��Ь
    else if(x==1) SetPos(X-K,Y),Color(1),cout<<"��"; //��ͨ 
}
void Cout(int i,int j,int a)
{
    if(m[i][j]==1) SetPos(i-K,j),Color(0),cout<<"��";
    if(m[i][j]==2) SetPos(i-K,j),Color(5),cout<<"��";
    if(m[i][j]==3) SetPos(i-K,j),Color(4),cout<<"��";
    if(m[i][j]==4) SetPos(i-K,j),Color(3),cout<<"��";
    if(m[i][j]==5&&(i!=X||j!=Y)) SetPos(i-K,j),Color(2),cout<<"��";
    if(m[i][j]==6&&a==1) SetPos(i-K,j),Color(7),cout<<"��",m[i][j]=7,Fen++;
    if(m[i][j]==7&&a==4) SetPos(i-K,j),cout<<"  ",m[i][j]=0;
    if(m[i][j]==7&&a!=4) SetPos(i-K,j),Color(7),cout<<"��";
//  if(m[i][j]==8) SetPos(i-K,j),cout<<"  ";
    if(m[i][j]==9) SetPos(i-K,j),Color(0),cout<<"���������ƶ�";
    if(m[i][j]==11&&Ee==0) SetPos(i-K,j),Color(0),cout<<"������  ը����  ���ο�";
    if(m[i][j]==11&&Ee==1) SetPos(i-K,j),Color(0),cout<<"������ ",Color(4),cout<<"����ը����",Color(0),cout<<" ���ο�";
    if(m[i][j]==12&&Ee==0) SetPos(i-K,j),Color(0),cout<<"    ������";
    if(m[i][j]==12&&Ee==1) SetPos(i-K,j),Color(0),cout<<"�������",Color(3),cout<<"����������";
    if(m[i][j]==13) SetPos(i-K,j),Color(0),cout<<"������Ծ���ɶ�����";
    if(m[i][j]==14) SetPos(i-K,j),Color(0),cout<<"�����ڿ�ʼ�����ͼ��";
    if(m[i][j]==15&&Ee==0) SetPos(i-K,j),Color(5),cout<<"1000��ͨ�أ�",Color(0),cout<<"�ո���ͣ";
    if(m[i][j]==15&&Ee==1) SetPos(i-K,j),Color(5),cout<<"̽��40��ͨ�أ�",Color(0),cout<<"�ո���ͣ";
    if(m[i][j]==15&&Ee==2) SetPos(i-K,j),Color(5),cout<<"׽��20��ͨ�أ�",Color(0),cout<<"�ո���ͣ";
    if(m[i][j]==16) SetPos(i-K,j),Color(5),cout<<"��";
    if(m[i][j]==17&&Ee==0) SetPos(i-K,j),Color(0),cout<<"����������Ʒ��";
    if(m[i][j]==17&&Ee==1) SetPos(i-K,j),Color(0),cout<<"����",Color(2),cout<<"�������֣�",Color(0);
    if(m[i][j]==17&&Ee==2) SetPos(i-K,j),Color(2),cout<<"���ᶯ����",Color(0);
    if(m[i][j]==18) SetPos(i-K,j),Color(0),cout<<"��Ҫ����Ľ�ɫ�����������£�";
    if(m[i][j]==19) SetPos(i-K,j),Color(0),cout<<"�����½�";
    if(m[i][j]==20&&Ee==2) SetPos(i-K,j),Color(3),cout<<"���ּ���������",Color(0);
    //���������ֵĻ�������ǰ��� (m[X-1][Y]>=9&&m[X-1][Y]<=20) һ�� 
    Color(0);
}
void Map(int x1,int x2,int a)
{
    SetPos(25,2);if(Bai!=0||Yin!=0||Can!=0) Color(9);else Color(1);
    if(Ee==0) cout<<"������"<<Fen<<"                     ",Color(0);if(Ee==1) cout<<"��̽�⣺"<<Sboom<<"                     ",Color(0);if(Ee==2) cout<<"���ռ���"<<Sstar<<"                     ",Color(0);
    SetPos(24,2);if(Ice!=0) Color(8);else Color(1);cout<<"�ٶȣ�"<<Slep<<"                     ",Color(0);
    bool Yan=0;
    for(register int i=x1;i>=x2;i--)
    for(register int j=1;j<=20;j++) Cout(i,j,a);
    if(Yin!=0) Wo(3);
    else if(Ta!=0) Wo(2);
    else if(a==0) Wo(1);
    else if(a==2) SetPos(X-K,Y),Color(1),cout<<"��";
}
void MoveStar(int x1,int x2)
{
    int n[30][21];memset(n,0,sizeof(n));
    for(register int i=x1;i>=x2;i--)
    for(register int j=1;j<=20;j++)
    {
        if(m[i][j]==16&&n[i-K][j]==0)
        {
            int kl=rand()%4;
            if(kl==0&&i-K<22&&m[i+1][j]==0) m[i][j]=0,m[i+1][j]=16,n[i+1-K][j]=1,SetPos(i-K,j),cout<<"  ",SetPos(i+1-K,j),cout<<"��";
            if(kl==1&&i-1>K&&m[i-1][j]==0) m[i][j]=0,m[i-1][j]=16,n[i-1-K][j]=1,SetPos(i-K,j),cout<<"  ",SetPos(i-1-K,j),cout<<"��";
            if(kl==2&&j+1<20&&m[i][j+1]==0) m[i][j]=0,m[i][j+1]=16,n[i-K][j+1]=1,SetPos(i-K,j),cout<<"  ",SetPos(i-K,j+1),cout<<"��";
            if(kl==3&&j-1>1&&m[i][j-1]==0) m[i][j]=0,m[i][j-1]=16,n[i-K][j-1]=1,SetPos(i-K,j),cout<<"  ",SetPos(i-K,j-1),cout<<"��";
        }
    }
}
void Sheng()
{
    RR++;
    if(K<-8) RR=5;
    if(K==-8) RR=0;
    if(RR==3) {int r=rand()%2;if(r==0) RR=0;}
    if(RR==4) RR=0;
    if(RR==0)
    {
        Ax: int Bx=0;
        for(int i=1;i<=20;i++) m[K+22][0]=0;
        for(int i=1;i<=20;i++)
        {
            int R=rand()%50;
            if(R<=10) {int S=rand()%3+1; for(int j=i;j<=i+S;j++) if(j<=20) m[K+22][j]=1;i+=S+1;Bx=1;continue;}
            if(R>10&&R<=12) {for(int j=i;j<=i+1;j++) if(j<=20) m[K+22][j]=2; i+=2;Bx=1;continue;}
            if(R>12&&R<=14) {for(int j=i;j<=i+1;j++) if(j<=20) m[K+22][j]=3; i+=2;continue;}
            if(R>14&&R<=16) {for(int j=i;j<=i+1;j++) if(j<=20) m[K+22][j]=6; i+=2;continue;}
            if(R==17) {m[K+22][i]=m[K+22][i+1]=m[K+22][i+2]=1; m[K+23][i+1]=4; i+=2;continue;}
            if(R>17&&R<=20&&Ee==1) {m[K+22][i]=m[K+22][i+1]=m[K+22][i+2]=1; m[K+23][i+1]=4; i+=2;continue;}
            if(R>20&&R<=30&&Ee==1) m[K+22][i]=10; i++;
        }if(Bx==0) goto Ax;
    }
    int Q=rand()%30; if(Q==0) {int QQ=rand()%20+1; if(m[K+22][QQ]==0) m[K+22][QQ]=16;}
    else if(Q<=2&&Ee==2) {int QQ=rand()%20+1; if(m[K+22][QQ]==0) m[K+22][QQ]=16;}
}
void Star()
{
    int W=rand()%10;if(K<20) W=rand()%7;if(Ee==1) W=3;
    if(W==0) {Color(5);cout<<"�����";Sleep(1000);tX=0;for(int i=1;i<=15;i++) {if(X-K<20) X+=2; else X++; Sheng(),K++,Fen++,Map(K+22,K-3,2),system("cls");}m[X-2][Y]=m[X-2][Y-1]=6,S=1;Sleep(10);}  
    if(W==1) {Color(5);cout<<"͸���ۣ�";Sleep(1000);system("color 3F");Sleep(100);if(X>2) m[X-2][Y]=m[X-2][Y-1]=6;Map(K+22,K-3,1);system("color 0F");}
    if(W==2) {Color(5);cout<<"���٣�";Sleep(1000);system("color 1F");Map(K+22,K-3,3);Ice=10;system("color 0F");if(X>2&&K>10) m[X-2][Y]=m[X-2][Y-1]=6;}
    if(W==3) {Color(5);cout<<"�������֣�";Sleep(1000);Fang=15;if(X>2&&K>10) m[X-2][Y]=m[X-2][Y-1]=6;}
    if(W==4) {Color(5);cout<<"�����ϣ�";Sleep(1000);system("color 5F");Map(K+22,K-3,0);Bai=15;system("color 0F");if(X>2&&K>10) m[X-2][Y]=m[X-2][Y-1]=6;}
    if(W==5) {Color(5);cout<<"����";Sleep(1000);system("color 2F");Yin=15;if(X>2) m[X-2][Y]=m[X-2][Y-1]=6;Map(K+22,K-3,0);system("color 0F");}
    if(W==6) {Color(5);cout<<"�˷ܼ���";Sleep(1000);system("color 4F");Sleep(100);Can=15;if(X>2) m[X-2][Y]=m[X-2][Y-1]=6;Map(K+22,K-3,1);system("color 0F");}
    if(W==7) {Color(5);cout<<"̤��ѥ��";Sleep(1000);system("color 6F");Sleep(100);Ta=10;}
    if(W==8) {Color(5);cout<<"ƽ̨��";Sleep(1000);system("color 7F");Sleep(100);for(int i=1;i<=20;i++) m[X-1][i]=1;Map(K+22,K-3,1);system("color 0F");}
    if(W==9) {Color(5);cout<<"ը�����壡";Sleep(1000);system("color 4F");for(int i=0;i<=5;i++){int kX=rand()%9-4;int kY=rand()%9-4;if(Y+kY>0&&Y+kY<=20) m[X+kX][Y+kY]=3;}tX=0;if(X>1) m[X-1][Y]=6;Map(K+22,K-3,0);system("color 0F");}
}
void Start()
{
    Color(5);
    SetPos(25,2);cout<<"   ������     ��    ";
    SetPos(24,2);cout<<"   ��  ��    ��     ";
    SetPos(23,2);cout<<"   ������  ��    �� ";
    SetPos(22,2);cout<<"   ��  �� ����������  ע�⣡";
    SetPos(21,2);cout<<"   ��  ��           ";
    SetPos(20,2);cout<<"   ������  ��������   ����ģʽ���޸ģ�";
    SetPos(19,2);cout<<"   ��  ��  ��    �� ";
    SetPos(18,2);cout<<"   ��  ��  ��    ��   ������Ҫͬʱ����";
    SetPos(17,2);cout<<"����   ��  ��������         ����������";
    SetPos(14,2);cout<<"        ��         ��    ";
    SetPos(13,2);cout<<"         ��        ��    ";
    SetPos(12,2);cout<<"      ������   ����������";
    SetPos(11,2);cout<<"         ��    ��  ��  ��";
    SetPos(10,2);cout<<"        ��     ����������";
    SetPos(9,2); cout<<"      �� ����  ��  ��  ��";
    SetPos(8,2); cout<<"     ��  �� �� ����������";
    SetPos(7,2); cout<<"         ��        ��    ";
    SetPos(6,2); cout<<"         ��        ��    ";
    SetPos(5,2); cout<<"         ��        ��    ֮ ·";
    SetPos(3,2);Color(0);cout<<"�� y ȷ��!";SetPos(3,10);Color(9);cout<<"    ��ʼ��Ϸ!    ";SetPos(2,10);Color(0);cout<<"    ը���籩!    ";SetPos(1,10);Color(0);cout<<"    ����֮ս!    ";
    SetPos(-1,1);Color(3);cout<<"ע�⣡���� ���Բ�����ƴ�����뷨!";
    SetPos(-2,5);Color(3);cout<<"��";Color(0);
    char tt;Ee=0;
    while(tt!='y')
    {
        tt=_getch();
        if(tt==72&&Ee!=0) Ee--;
        if(tt==80&&Ee!=2) Ee++;
        SetPos(3,10);if(Ee==0) Color(9);else Color(0);cout<<"    ��ʼ��Ϸ!    ";Color(0);
        SetPos(2,10);if(Ee==1) Color(9);else Color(0);cout<<"    ը���籩!    ";Color(0);
        SetPos(1,10);if(Ee==2) Color(9);else Color(0);cout<<"    ����֮ս!    ";Color(0);
    }system("cls");
    if(Ee==1) m[9][8]=m[9][9]=m[9][10]=m[9][11]=m[9][12]=10,m[9][14]=m[9][15]=6;
}
void Return()
{
    for(int i=0;i<=5;i++)
    {
        system("color 1A");Sleep(10);
        system("color 2B");Sleep(10);
        system("color 3C");Sleep(10);
        system("color 4D");Sleep(10);
        system("color 5D");Sleep(10);
        system("color 6E");Sleep(10);
        system("color 7F");Sleep(10);
    }system("color 0F");Map(K+22,K-3,4);system("cls");
    while(K>-6) {for(int i=0;i<=20;i++) m[K+21][i]=0;K--;}
    m[6][16]=4;m[12][13]=16;
    m[9][12]=m[9][13]=6;system("cls");
}
int main()
{
    system("mode con cols=42 lines=30");
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    srand((unsigned)time(NULL));
    Start();
    ST:
    X=3,Y=2,dx=3,dy=2,K=-7;
    tX=Fen=RR=S=Er=Sstar=Sboom=Win=0;
    Ta=Fang=Ice=Bai=Yin=Can=0;
    Map(K+22,K-3,0);
    while(X>K-3||dx>K-3)
    {
        S++,U++;
        if(Fen<0) Fen=0;
        if(Ee==0&&Fen>1000) {Win=1;break;}if(Ee==1&&Sboom>=40) {Win=1;break;}if(Ee==2&&Sstar>=20) {Win=1;break;}
        if(K<=5) Slep=20;if(K>5&&K<=10) Slep=15;if(K>10&&K<=20) Slep=10;if(K>20&&K<=30) Slep=8;if(K>30&&K<=70) Slep=7;if(K>70&&K<=150) Slep=6;if(K>150&&K<=250) Slep=5;if(K>250&&K<=400) Slep=4;if(K>400&&K<=600) Slep=3;if(K>600) Slep=2;
        if(Sstar<=5) Su=5;if(Sstar>5&&Sstar<=10) Su=4;if(Sstar>10&&Sstar<=15) Su=3;if(Sstar>15&&Sstar<=20) Su=2;if(Sstar>20&&Sstar<=30) Su=1;
        if(Ice!=0) Slep=20;
        if(X<=K-3&&dx>K-3) X=dx,Y=dy;
        if(S==Slep)
        {
            K++,S=0;
            if(Bai!=0||Yin!=0||Can!=0) Fen+=2;else Fen++;
            if(Ta>0) Ta--;if(Fang>0) Fang--;if(Bai>0) Bai--;if(Ice>0) Ice--;if(Yin>0) Yin--;if(Can>0) Can--;
            if(Ta<0) Ta=0;if(Fang<0) Fang=0;if(Bai<0) Bai=0;if(Ice<0) Ice=0;if(Yin<0) Yin=0;if(Can<0) Can=0;
            system("cls"),Sheng();
        }
        if(GetAsyncKeyState(VK_UP)&0x8000&&TT==0&&Ta==0&&Er<2) TT++,tX+=4,Er++;
        else if(GetAsyncKeyState(VK_UP)&0x8000&&TT==0&&Can!=0) TT++,tX+=7,Er++;
        else if(GetAsyncKeyState(VK_UP)&0x8000&&TT==0&&Ta!=0) SetPos(X-K,Y),cout<<"  ",X++,tX=Er=0;
        if(GetAsyncKeyState(VK_DOWN)&0x8000&&Ty==0) Ty++,SetPos(X-K,Y),cout<<"  ",tX=0,X-=2;
        if((GetAsyncKeyState(VK_UP) & 0x8000) ?0:1) TT=0;
        if((GetAsyncKeyState(VK_DOWN) & 0x8000) ?0:1) Ty=0;
        if(GetAsyncKeyState(VK_LEFT)&0x8000&&Y>1) SetPos(X-K,Y),cout<<"  ",Y--;
        if(GetAsyncKeyState(VK_RIGHT)&0x8000&&Y<20) SetPos(X-K,Y),cout<<"  ",Y++;
        if(kbhit()) {char g=_getch();if(g==' ') Sleep(100),SetPos(24,8),sy++,Color(0),system("pause");}
        if(sy>=1) SetPos(24,8),cout<<"                           ",sy=0;
        if(U>=Su) {U=0;if(Ee==2) MoveStar(K+22,K-3);}
        Map(K+22,K-3,0); Sleep(50);
    }
    if(Win==0) {SetPos(25,8),system("color 7F"),Color(4),cout<<"You! Die!!!",Sleep(1000);}
    else {SetPos(25,8),system("color 6E"),Color(3),cout<<"You! Win!!!",Sleep(1000);}
    SetPos(24,5),cout<<"Please point 'y' to Play AGain.";Color(0);
    A:char e=_getch();if(e=='y') Return();else goto A;goto ST;
    return 0;
}
