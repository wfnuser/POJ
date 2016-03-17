#include<iostream>
#include<cstdlib>

using namespace std;

void qsort(int a[], int l, int r)
{
	if(l>=r) return;
	int p = l;
	int s = l+1;
	int e = r;
	int temp;
	
	while(s<e){
		while(a[s]<=a[p]&&s<=e) s++;
		while(a[e]>=a[p]&&s<=e) e--;
		if(s<=e){
			temp = a[s];
			a[s] = a[e];
			a[e] = temp;
		}
	}

	temp = a[p];
	a[p] = a[e];
	a[e] = temp;

	qsort(a,l,e-1);
	qsort(a,e+1,r);
}

int main()
{
	int n = 3;
	int a[3] = {1,-3,2};

	qsort(a,0,n-1);

	for(int i=0; i<=n-1; i++)
		cout<<a[i]<<" ";

}
