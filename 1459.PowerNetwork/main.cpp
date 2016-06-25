#include<iostream>
#include<cstdio>

using namespace std;

const int inf = 1000000000;
const int maxn = 20000, maxm = 500000;

class Edge
{
	public:
		int v,f,nxt;
};

int n, src, sink;
int g[maxn+10];
int nume;

Edge e[maxn*2+10];

void addedge(int u, int v, int c)
{
	e[++nume].v = v;
	e[nume].f = c;
	e[nume].nxt = g[u];
	g[u] = nume;

	e[++nume].v = u;
	e[nume].f = 0;
	e[nume].nxt = g[v];
	g[v] = nume;
}

void init()
{
	memset(g, 0, sizeof(g));
	nume = 1;
}

queue<int> que;
bool vis[maxn+10];
int dist[maxn+10];

void bfs()
{
	memset(dist, 0, sizeof(dist));
	while(!que.empty()) que.pop();
	vis[src] = true;
	que.push(src);

	while(!que.empty()) {
		int u = que.front();
		que.pop();

		for(int i = g[u]; i; i=e[i].nxt)
			if(e[i].f && !vis[e[i].v]) {
				que.push(e[i].v);
				dist[e[i].v] = dist[u] + 1;
				vis[e[i].v] = true;
			}
	
	}
}

int dfs(int u, int delta)
{
	if(u == sink) {
		return delta;
	} else {
		int ret = 0;
		for (int i = g[u]; delta && i; i = e[i].nxt)
			if (e[i].f && dist[e[i].v] == dist[u] + 1) { 
				int dd = dfs(e[i].v, min(e[i].f, delta));
				e[i].f -= dd;
				e[i ^ 1].f +=dd;
				delta -= dd;
				ret += dd;
			}
		return ret;
	}
	
}

int maxflow()
{
	int ret = 0;
	while (1) {
		memset(vis, 0, sizeof(vis));
		bfs();
		if (! vis[sink]) return ret;
		ret += dfs(src, inf);
	}
}

int main()
{
	
}









