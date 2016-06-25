/*********
PRO: POJ 1698
TIT: Alice's Chance
DAT: 2013-08-12
AUT: UKean
EMA: huyocan@163.com
*********/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define  INF 1e9
using namespace std;
queue<int> que;//广搜需要使用的队列
int M;//M是点数
int s,t;//源点和汇点
int flow[405][405];//残流量
int p[405];//广搜记录路径的父节点数组
int a[405];//路径上的最小残量
int cap[405][405];//容量网络
int ans;//最大流
int data[30][10];//存读入数据的部分
int sum;//存拍所有电影需要的天数
int read()
{
    int flim_num;cin>>flim_num;
    for(int i=0;i<flim_num;i++)
        for(int j=0;j<9;j++)
        cin>>data[i][j];
 
    s=0;t=1;//源点汇点
 
    for(int i=M=0;i<flim_num;i++) M=max(data[i][8],M);
    M=M*7+30;//算出大概的总的点数
 
    memset(cap,0,sizeof(cap));
    //2 --21 是电影,22后面的点表示时间
    for(int i=2;i<flim_num+2;i++)
        cap[0][i]=data[i-2][7];//超级源点到每个电影的边
    //处理电影到每天
    for(int i=0;i<flim_num;i++)
        for(int j=0;j<7;j++)//j是一周的第几天
            if(data[i][j]==1)
            for(int k=0;k<data[i][8];k++)//k是第几周
            {
                cap[i+2][k*7+j+22]=1;//电影到第几天的边的容量
                cap[k*7+j+22][1]=1;//第几天到汇点的边的容量
            }
    sum=0;
    for(int i=0;i<flim_num;i++)
        sum+=data[i][7];//计算出拍完所有的电影需要的天数
    return 1;
}
 
int deal()//增广路算法
{
    memset(flow,0,sizeof(flow));
    ans=0;
    while(1)
    {
        memset(a,0,sizeof(a));
        a[s]=INF;
        que.push(s);
        while(!que.empty())
        {
            int u=que.front();que.pop();
            for(int v=1;v<=M;v++)
            if(!a[v]&&cap[u][v]-flow[u][v]>0)
            {
                p[v]=u;
                que.push(v);
                a[v]=min(a[u],cap[u][v]-flow[u][v]);//路径上的最小残流量
            }
        }
        if(a[t]==0) break;
        for(int u=t;u!=s;u=p[u])
        {
            flow[p[u]][u]+=a[t];
            flow[u][p[u]]-=a[t];
        }
        ans+=a[t];
    }
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        read();
        if(deal()==sum)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}