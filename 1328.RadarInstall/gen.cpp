#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int d = 4;
	int n=100;
	int t;
	cout<<n<<" "<<d<<endl;
	for(int i=0; i<=n-1; i++){
		//t=0;
		//if(n%7==0) t=1;
		cout<<(-15 + rand()%31)<<" "<<rand()%5<<endl;		
	}
	cout<<0<<" "<<0;
}
