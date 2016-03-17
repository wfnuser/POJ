#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

class node
{
	public:
		float x;
		float y;
		float b;
		float e;
};

node a[20000];

void quicksort(node a[], int l, int r)
{
	if(l>=r) return;
	int p = l;
	int b = l+1;
	int e = r;
	float temp;
	
	while(b<=e){
		while(b<=e&&a[b].b<=a[p].b) b++;
		while(b<=e&&a[e].b>=a[p].b) e--;
		if(b<=e){
			temp = a[e].b;
			a[e].b = a[b].b;
			a[b].b = temp;
			temp = a[e].e;
			a[e].e = a[b].e;
			a[b].e = temp;
		} 
	}
	temp = a[e].b;
	a[e].b = a[p].b;
	a[p].b = temp;
	temp = a[e].e;
	a[e].e = a[p].e;
	a[p].e = temp;

	quicksort(a,l,e-1);
	quicksort(a,e+1,r);
}

int main()
{
	int n,d;
	float range;
	int sum;
	int flag = 0;
	float tempb;
	float tempe;
	int num;
	int times = 1;
	while(cin>>n>>d && n!=0 && d!=0){
		flag = 0;
		sum = 0;
		num = 0;
		for(int i=0; i<=n-1; ++i){
			cin>>a[i].x>>a[i].y;
			if(d<a[i].y) {flag=1;break;}
			range = sqrt(d*d - a[i].y * a[i].y);
			a[i].b = a[i].x - range;
			a[i].e = a[i].x + range;
		}

		cout<<"Case "<<times<<": ";
		if(flag){cout<<-1<<endl;continue;}
	
		//for(int i=0;i<=n-1;i++){
		//	cout<<a[i].b<<" "<<a[i].e<<endl;
		//}
		//cout<<"<<<<<<<<<<<<<"<<endl;

		quicksort(a,0,n-1);
		
		//for(int i=0;i<=n-1;i++){
		//	cout<<a[i].b<<" "<<a[i].e<<endl;
		//}
		//cout<<"<<<<<<<<<<<<<"<<endl;

		while(num<=n-1){
			sum++;
			tempb = a[num].b;
			tempe = a[num].e;
			for(int j=num+1;j<=n-1;j++){
				if(a[j].b<tempe||fabs(tempe-a[j].b)<1e-6){
					if(tempe>a[j].e)
						tempe = a[j].e;
					num = j;
				}
			}
			num++;
		}
		cout<<sum<<endl;
		times++;
	}



}
