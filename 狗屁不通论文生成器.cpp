#include<bits/stdc++.h>
using namespace std; 
int j;
string nouns[200]={"С��","̫��","����","����","�ݵ�","�ܶ�����","HOMO","�ܸ�","��ΰ","ikun","С������","��ǿ","��ɽ��"};int _nouns=13;
string verbs[200]={"����","�ɳ�","����","��˯","����","ͻ��","114514","1919810","����rap����"};int _verbs=9;
string adj[200]={"���յ�","δ����","������","ʹ���","������","���и��������","404��","��ϰ������"};int _adj=8;
string adv[200]={"Ѹ�ٵ�","���ֵ�","��ŭ��","���ŵ�","���ŵ�","�¸ҵ�"};int _adv=7;
string like[200]={"��ѩ�а����ĺ�÷","���峿�����̫��","��й������Ƥ��","��һ����ҫ�Ĺ�","����������е�����","����ϰ����Ĺ�","��ͬ��ɽ�׵ļ���"};int _like=7;
string connect[200]={"��","��","��"};int _connect=3;
string ques[200]={"Ϊʲô","�����","��ʱ����"};int _ques=3;
string gt[200]={"��ô","��һ��","����"};int _gt=3;
string gtback[200]={"��","��","ѽ"};int _gtback=3;
string obq[200]={"�ѵ�","����","��ô"};int _obq=3;
string obend[200]={"��","��"};int _obend=2;
string conj1[200]={"�������","��Ȼ���","���������Ļ�","������","�ܵ���˵","����","һ�������������ŵ���ʵ��"};int _conj1=7;
string famous[200]={"����������˵��:�ɹ�����1%����к�99%��Ŭ��.","��ɽ��ɽ������ˮ��ɽ,","ʧ���ǳɹ�֮ĸ,",
"���˼�ڡ��ʱ��ۡ����ᵽ:��10%������,�ʱ��ͻ��Ծ����,.....��100%������,�ʱ��͸Ҽ�̤�˼䷨��,��300%������,�ʱ��᲻�˱������ķ���.",
"�����˵,�˵���ְ������̽������.",
"�׷������ռ����ᵽ,�˵����������޵ģ����ǣ�Ϊ������������޵ģ���Ҫ�����޵�������Ͷ�뵽���޵�Ϊ�������֮��ȥ��" ,
"�����Ϊ,�˵��ǻ�����������Կ�ף�һ�ѿ������֣�һ�ѿ�����ĸ��һ�ѿ���������֪ʶ��˼�롢����������С�",
"����˹̹˵,��ֻ����������ᣬ�����ҳ��Ƕ��ݶ��з��յ����������塣" ,
"³Ѹ����, ϣ���Ǹ����ڴ��ڵģ��д��ڣ�����ϣ������ϣ�������ǹ�����" ,
"ɯʿ����˵, ����ʱ����ˣ�ʱ��Ҳ��������",
"���������˵��,�ƽ�ʱ����������ǰ���������Ǳ���" ,
"��ΰ��˵����������,һ��\"���������ѷ����\",����\"�ܸ磬��Ҫ��\"��",
"�ܸ�Ҳ��˵��,���ҿ����㷢����������",
"��ɽ�׽���һ�仰:\"�������!\"",
"�ڶ�ѧ���ڿ����ж�θп�:\"FUCK CCF!\" ",
" \"�������漣��ƭ�ֹ�������\n\
���ѹ��Ż�������ʡһ��\n\
n ��������A C �Զ�����\n\
ö�ٳ����㣬���ַַ�����\n\
��ѧ�ȴ���ģп�������\n\
��٣ԣ̣ţ����ƣգˣš�\n\
ģ��̣ͣţ�̰�Ļ��ãš�\n\
��Ҫƭ���֣���Ҫ�з�����\n\
ͼ�۱�ģ�壬���۱���ʽ��\n\
���汳���̣��߾������롣\n\
�����û�����ɴ���������\" "
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
    else cout<<obq[ob1]<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<"��"<<verbs[v]<<obend[ob2]<<"?";
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
    fp=freopen("����.txt","w",stdout);
    int sq=rand_number(6666)%3;
    int paras=rand_number(3333)%300+500;
    for(j=1;j<=paras;j++){
        paragraph(j+1);
    }
    fclose(fp);
    system("start ����.txt");
    return 0;
}
