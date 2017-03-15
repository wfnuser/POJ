/************************
author: wfnuser date www.element14.site
title: Power String 
For DS
************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

char a[1000010];
int len;
int p[1000010];

void getP() {
	p[1] = 0;
	int j = 0;
	int i = 0;
	for (i = 2; i <= len; i++) {
		while (j > 0 && a[j+1] != a[i]) {
			j = p[j];
		}
		if (a[j+1] == a[i]) j++;
		p[i] = j;
	}
}

int main()
{
	while(scanf("%s", a+1) != EOF) {
		if (a[1] == '.')
			break;
		len = strlen(a+1);
		getP();
		if(len % (len - p[len]) == 0) printf("%d\n", len / (len - p[len]));
		else printf("1\n");
	}

}

