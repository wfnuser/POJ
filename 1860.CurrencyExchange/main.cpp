#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue> 
 
using namespace std;  

const int N = 110;  
int n, m, s;  
double dis[N], v, rate[N][N], cost[N][N];  

bool spfa(int start)
{
	bool inq[110];
	memset(inq, 0, sizeof(inq));  
   	memset(dis, 0, sizeof(dis)); 
	dis[start] = v;
	queue<int> Q;
	Q.push(start);
	inq[start] = true;

	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		inq[x] = false;
		for(int i=0; i<=n; i++){
			if(dis[i]<(dis[x] - cost[x][i]) * rate[x][i])
			{
				dis[i] = (dis[x] - cost[x][i]) * rate[x][i];  
				if(dis[start] > v)  
					return true;  
				if(!inq[i])  
				{  
					Q.push(i);  
					inq[i] = true;  
				}  
			}
		}
	}
	return false;
}

int main()
{
	int i, j;
	int a, b;
	double rab,rba,cab,cba;  
	while(cin>>n>>m>>s>>v){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i == j) rate[i][j] = 1;
				else rate[i][j] = 0;
				cost[i][j] = 0;
			}
		}
		for(i = 0; i < m; i++)  
		{  
			scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);  
			rate[a][b] = rab;  
			rate[b][a] = rba;  
			cost[a][b] = cab;  
			cost[b][a] = cba;  
		}  
		if(spfa(s))  
           		printf("YES\n");  
        	else  
            		printf("NO\n"); 
	}
}
