#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<math.h>

using namespace std;

void quicksort(int pos[100][2],int l,int r)
{
	if(l>=r) return;

	int temp;
	int s = l+1;
	int p = l;
	int e = r;

	while(s<=e){
		while(s<=e&&pos[s][0]<=pos[p][0]) s++;
		while(s<=e&&pos[e][0]>=pos[p][0]) e--;
		if(s<=e){

			temp = pos[s][0];
			pos[s][0] = pos[e][0];
			pos[e][0] = temp;
			
			temp = pos[s][1];
			pos[s][1] = pos[e][1];
			pos[e][1] = temp;
			
		}
	}

	temp = pos[p][0];
	pos[p][0] = pos[e][0];
	pos[e][0] = temp;
	
	temp = pos[p][1];
	pos[p][1] = pos[e][1];
	pos[e][1] = temp;

	quicksort(pos,l,e-1);
	quicksort(pos,e+1,r);
}

float dist(float x, float y, float rx)
{
	float d;
	d = y*y +  (rx-x)*(rx-x);
	return d;
}

int solve(int n, int d)
{
	int sum = 0;
	float rx = 0;
	float x,y;
	for(int i=0; i<=n-1; i++){
		x = pos[i][0];
		y = pos[i][1];
		if(d<y) {sum =-1;break;}
		rx = sqrt(d*d - y*y) + x;
		sum++;
		for(int j=i+1;j<=n-1;j++){
			x = pos[j][0];
			y = pos[j][1];
			if(dist(x,y,rx)>d){
			
			}
		}
	}
}

int main()
{
	int n,d;
	int pos[100][2];

	while(1){
		cin>>n>>d;
		if(n==0&&d==0) break;
		for(int i=0; i<=n-1; i++)
			cin>>pos[i][0]>>pos[i][1];
		quicksort(pos,0,n-1);
		
		solve(n-1,d);
	}	
}
