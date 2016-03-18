#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main()
{
	int t;
	int n;
	int a[100];
	int p[100];
	int cur;
	int lst;
	int count;
	cin>>t;	
	for(int i=0;i<=t-1;i++){
		cin>>n;
		lst = cur = 0;

		for(int i=0;i<=n-1;i++){
			cin>>cur;
			cur = cur + i;
			for(int j=lst; j<=cur-1; j++)
				p[j] = 0;
			p[cur] = 1;
			lst = cur + 1;
		}	

		//for(int i=0;i<=cur;i++){
		//	cout<<p[i]<<" ";
		//}
		//cout<<endl;
		
		for(int i=0;i<=cur;i++){
			count=2;
			if(p[i]){
				for(int j=i-1;j>=0;j--){
					if(p[j]==-1){
						count++;
					}	
					if(p[j]==0){
						p[j]=-1;
						p[i]=-1;
						break;
					}
				}
				cout<<count/2<<" "; 
			}
		}
		cout<<endl;
	}
}
