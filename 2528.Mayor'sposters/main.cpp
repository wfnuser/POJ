#include<iostream>
#include<cstdlib>

using namespace std;

#define N 40500;
int n;

struct node
{
	int l,r,flag;
}tree[N*4];

struct Inter
{
	int l,r;
}inter[N];

int vis[N];

void build(int l, int r, int pos)
{
	tree[pos].l = l; tree[pos].r = r;

}

int main()
{
	
}
