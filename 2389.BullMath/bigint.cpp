#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char a[100];
char b[100];
int la,lb;
int r[20000];
int carry[20000];
int temp;
int flag;

int main()
{
	
	
	
		memset(r,0,sizeof(r));
		memset(carry,0,sizeof(carry));
		cin>>a>>b;
		la = strlen(a);
		lb = strlen(b);	
		temp = 0;
		flag=1;
		for(int i=0;i<=lb-1;i++){
			for(int j=0;j<=la-1;j++){
				r[i+j] = r[i+j]	+ (a[la-1-j]-'0') * (b[lb-1-i] - '0') ;
				temp = r[i+j]/10;
				r[i+j+1] = r[i+j+1] + temp;
				r[i+j] = r[i+j] % 10;
			}
		}

		for(int i = la+lb+1; i>=0; i--){
			if(flag&&r[i]==0) {
				continue;
			}
			cout<<r[i];
			flag=0;
		}
}
