#include<bits/stdc++.h>
using namespace std; 
int j;
string nouns[200]={"小明","太阳","花儿","世界","草地","奋斗者们","HOMO","杰哥","阿伟","ikun","小黑子们","华强","穿山甲"};int _nouns=13;
string verbs[200]={"绽放","成长","毁灭","沉睡","哭泣","突破","114514","1919810","唱跳rap篮球"};int _verbs=9;
string adj[200]={"昔日的","未来的","美丽的","痛苦的","新生的","富有革命精神的","404的","练习两年半的"};int _adj=8;
string adv[200]={"迅速地","快乐地","愤怒地","慌张地","自信地","勇敢地"};int _adv=7;
string like[200]={"如雪中傲立的寒梅","如清晨升起的太阳","像泄了气的皮球","像一道闪耀的光","像蔡徐坤手中的篮球","像瓜老板卖的瓜","如同穿山甲的鸡汤"};int _like=7;
string connect[200]={"着","了","过"};int _connect=3;
string ques[200]={"为什么","如何让","何时能有"};int _ques=3;
string gt[200]={"多么","好一个","真是"};int _gt=3;
string gtback[200]={"啊","哇","呀"};int _gtback=3;
string obq[200]={"难道","怎能","怎么"};int _obq=3;
string obend[200]={"吗","呢"};int _obend=2;
string conj1[200]={"无论如何","既然如此","根据上述的话","如此这般","总的来说","并且","一个令人难以置信的事实是"};int _conj1=7;
string famous[200]={"爱迪生曾经说过:成功来自1%的灵感和99%的努力.","金山银山不如绿水青山,","失败是成功之母,",
"马克思在《资本论》中提到:有10%的利润,资本就会活跃起来,.....有100%的利润,资本就敢践踏人间法律,有300%的利润,资本会不顾被绞死的风险.",
"哥白尼说,人的天职在勇于探索真理.",
"雷锋曾在日记中提到,人的生命是有限的，可是，为人民服务是无限的，我要把有限的生命，投入到无限的为人民服务之中去。" ,
"雨果认为,人的智慧掌握着三把钥匙，一把开启数字，一把开启字母，一把开启音符。知识、思想、幻想就在其中。",
"爱因斯坦说,人只有献身于社会，才能找出那短暂而有风险的生命的意义。" ,
"鲁迅讲到, 希望是附丽于存在的，有存在，便有希望，有希望，便是光明。" ,
"莎士比亚说, 抛弃时间的人，时间也抛弃他。",
"马克吐温曾说过,黄金时代在我们面前而不在我们背后。" ,
"阿伟曾说过两句名言,一是\"这个彬彬就是逊啦。\",二是\"杰哥，不要！\"。",
"杰哥也曾说过,让我康康你发育正不正常",
"穿山甲讲过一句话:\"鸡汤来喽!\"",
"众多学子在考试中多次感慨:\"FUCK CCF!\" ",
" \"暴力出奇迹，骗分过样例。\n\
爆搜挂着机，打表出省一。\n\
n 方过百万，A C 自动机。\n\
枚举出标算，部分分分析。\n\
数学先打表，ＤＰ看运气。\n\
穷举ＴＬＥ，递推ＵＫＥ。\n\
模拟ＭＬＥ，贪心还ＣＥ。\n\
想要骗到分，就要有方法。\n\
图论背模板，数论背公式。\n\
动规背方程，高精背代码。\n\
如果都没背，干脆输样例。\" "
};int _famous=17;
bool said[4];
int checkfame(int x){
    if(said[x])return x;
    else{
        for(int i=1;i<=11;i++){
            if(said[x])return x;
        }
    }
    return -1;
} 
int rand_number(int x){
    srand(time(NULL)+x*x);
    return rand()+x*x;
}
void say_sentence(int y){
    int GCCsb=rand_number(2212+y)%_conj1;
    if(GCCsb%2==0)cout<<conj1[GCCsb]<<","; 
    int n=rand_number(233+y)%_nouns;
    int v=rand_number(333+y)%_verbs;
    int aj=rand_number(444+y)%_adj;
    int av=rand_number(555+y)%_adv;
    int alike=rand_number(666+y)%_like;
    int c=rand_number(777+y)%_connect;
    cout<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<verbs[v]<<connect[c]<<".";
}

void question(int y){
    int n=rand_number(233+y)%_nouns;
    int v=rand_number(333+y)%_verbs;
    int aj=rand_number(444+y)%_adj;
    int av=rand_number(555+y)%_adv;
    int alike=rand_number(666+y)%_like;
    int c=rand_number(777+y)%_connect;
    int qq=rand_number(888+y)%_ques;
    int num=rand_number(999+y)%2;
    int ob1=rand_number(1111+y)%_obq;
    int ob2=rand_number(2222+y)%_obend;
    if(num)cout<<ques[qq]<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<verbs[v]<<connect[c]<<"?";
    else cout<<obq[ob1]<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<"不"<<verbs[v]<<obend[ob2]<<"?";
}
void gts(int y){
    int n=rand_number(233+y)%_nouns;
    int v=rand_number(333+y)%_verbs;
    int aj=rand_number(444+y)%_adj;
    int av=rand_number(555+y)%_adv;
    int gg=rand_number(8888+y)%_gt;
    int ggg=rand_number(9999+y)%_gtback;
    cout<<adj[aj]<<nouns[n]<<gt[gg]<<adv[av]<<verbs[v]<<gtback[ggg]<<"!";
}
void paragraph(int y){
    cout<<"    ";
    y=rand_number(j+1)%12+18;
    for(int i=1;i<=y;i++){
        int u=rand_number(i+11+j)%3;
        if(u)say_sentence(i+56+y);
        else{
            int uu=rand_number(i+22+y)%100;
            if(uu<=20)gts(i+888+y);
            else if(uu<=52) question(i+8848+y*y);
            else cout<<famous[rand_number(i+4+y)%_famous];
        }
    }
    cout<<endl;
}
int main(){
	FILE* fp;
    fp=freopen("文章.txt","w",stdout);
    int sq=rand_number(6666)%3;
    int paras=rand_number(3333)%300+500;
    for(j=1;j<=paras;j++){
        paragraph(j+1);
    }
    fclose(fp);
    system("start 文章.txt");
    return 0;
}
