#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;

int pp,qq,rr,ss,tt;
int flag = 0;
stack<char> stk; 

void funa()
{
	int a,b;
	a = stk.top();
	stk.pop();
	b = stk.top();
	stk.pop();
	stk.push(a||b);
}

void funk()
{
        int a,b;
        a = stk.top();
        stk.pop();
        b = stk.top();
        stk.pop();
        stk.push(a&&b);
}

void func()
{
        int a,b;
        a = stk.top();
        stk.pop();
        b = stk.top();
        stk.pop();
        stk.push(!a||b);
}

void fune()
{
        int a,b;
        a = stk.top();
        stk.pop();
        b = stk.top();
        stk.pop();
        stk.push(a==b);
}

void funn()
{
        int a;
        a = stk.top();
        stk.pop();
        stk.push(!a);
}

void print(stack<char> &s)
{
    if(s.empty())
    {
	cout <<"emepty";
        cout << endl;
        return;
    }
    char x= s.top();
    s.pop();
    print(s);
    s.push(x);
    cout << x << " ";
 }

int main()
{
	char s[110];
	int len;
	while(cin>>s && s[0]!='0'){
		flag = 0;
		len = strlen(s);
		
		for(pp=0;pp<=1;pp++){
			for(qq=0;qq<=1;qq++){
				for(rr=0;rr<=1;rr++){
					for(ss=0;ss<=1;ss++){
						for(tt=0;tt<=1;tt++){							
							for(int i=len-1;i>=0;i--){
								switch(s[i]){
									case 'p' : stk.push(pp);break;
									case 'q' : stk.push(qq);break;
									case 'r' : stk.push(rr);break;
									case 's' : stk.push(ss);break;
									case 't' : stk.push(tt);break;
									case 'A' : funa();break;
									case 'N' : funn();break;
									case 'C' : func();break;
									case 'E' : fune();break;
									case 'K' : funk();break;
								}
							}
							if(!stk.top()) flag=1;
							stk.pop();
							if(flag) break;
						}
						if(flag) break;
					}
					if(flag) break;
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) cout<<"not"<<endl;
		else cout<<"tautology"<<endl;
	}
}
