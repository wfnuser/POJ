/************************
author: wfnuser 2016.4.29 www.geniuslink.org
title: NCA
For ACM training
************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

const int MAXN = 1e4+10;

struct Edge
{
	int to,next;
}edge[MAXN];

int dp[MAXN],head[MAXN],fa[MAXN][20],e;

inline void addEdge(int u,int v){
	edge[e].to = v;
	edge[e].next = head[u];
	head[u] = e ++;
}

void dfs(int u){
	for(int i = head[u];~i;i = edge[i].next){
		int v = edge[i].to;
		dp[v] = dp[u] + 1;
		dfs(v);
	}
}

void doubleAdd(int n){
	for(int i = 1;i < 20;i ++){
		for(int j = 1;j <= n;j ++)
			fa[j][i] = fa[fa[j][i-1]][i-1];
	}   
}

int lca(int u,int v){
	if(dp[u] < dp[v]) swap(u,v);
	int d = dp[u] - dp[v];
	for(int i = 0;i < 20;i ++){
        if((1 << i) & d) u = fa[u][i];
	}
	if(u == v) return v;
	for(int i = 19;i >= 0;i --){
		if(fa[u][i] != fa[v][i]){
				u = fa[u][i];
				v = fa[v][i];
		}
	}
	return fa[u][0];
}

int main(){
	int t,n,u,v,root;
	scanf("%d",&t);
	while(t--){
		e = 0;
		memset(fa,0,sizeof fa);
		memset(head,-1,sizeof head);
		scanf("%d",&n);
		for(int i = 1;i < n;i ++){
			scanf("%d%d",&u,&v);
			addEdge(u,v);
			fa[v][0] = u;
		}
		scanf("%d%d",&u,&v);
		for(int i = 1;i <= n;i ++) if(fa[i][0] == 0) root = i;
		dp[root] = 0;
		dfs(root);
		doubleAdd(n);
		printf("%d\n",lca(u,v));
	}
	return 0;
}

