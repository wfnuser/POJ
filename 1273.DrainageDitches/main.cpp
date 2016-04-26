#include<iostream>
#include<string.h>
#include<cstdio>
#include<queue>

using namespace std;
#define min(a,b) (a<b?a:b)
#define INF 1000000
const int MAX = 210;

struct Node
{
		int c;
		int f;
};

int sx,ex;
int pre[MAX];
Node map[MAX][MAX];

int n,m;

bool BFS()
{
	memset(pre,0,sizeof(pre));
	queue<int> Q;
	Q.push(sx);
	pre[sx] = 1;
	while(!Q.empty()){
		int d = Q.front();
		Q.pop();
		for(int i=1;i<=n;i++){
			if(!pre[i]&&map[d][i].c-map[d][i].f){
				pre[i] = pre[d] + 1;
				Q.push(i);
			}
		}
	}
	return pre[ex]!=0;
}

int dinic(int pos, int flow)
{
	int f = flow;
	if(pos == ex)
		return flow;
	
	for(int i=1;i<=n;i++){
		if(map[pos][i].c-map[pos][i].f && pre[pos]+1==pre[i]){
			int a = map[pos][i].c - map[pos][i].f;
			int t = dinic(i,min(a,flow));
			map[pos][i].f+=t;
			map[i][pos].f-=t;
			flow-=t;
			return t;
		}
	}
	return f-flow;
}

int solve()
{
	int sum=0;
	cout<<"solve start"<<endl;
	while(BFS()){
		sum += dinic(sx,INF);
	}
	return sum;
}

int main()
{
	int u,v,w;

	while(cin>>m>>n){
		sx = 1;
		ex = n;
		cout<<"start"<<endl;
		memset(map,0,sizeof(map));

		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			map[u][v].c+=w;
		}
		cout<<"end"<<endl;
		cout<<solve()<<endl;
	}

	return 0;

}
