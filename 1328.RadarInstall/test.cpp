#include<iostream>
#include<cstdlib>

using namespace std;

void qsort(int a[100][2], int l, int r)
{
	if(l>=r) return;
	int p = l;
	int s = l+1;
	int e = r;
	int temp;
	
	while(s<=e){
		while(a[s][0]<=a[p][0]&&s<=e) s++;
		while(a[e][0]>=a[p][0]&&s<=e) e--;
		if(s<=e){
			temp = a[s][0];
			a[s][0] = a[e][0];
			a[e][0] = temp;
		}
	}

	temp = a[p][0];
	a[p][0] = a[e][0];
	a[e][0] = temp;

	qsort(a,l,e-1);
	qsort(a,e+1,r);
}

int main()
{
	int n = 3;
	int a[100][2];

	for(int i=0;i<=n-1;i++){
		cin>>a[i][0]>>a[i][1];
	}
	qsort(a,0,n-1);

	for(int i=0; i<=n-1; i++)
		cout<<a[i][0]<<" ";

}
