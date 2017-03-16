/************************
author: wfnuser date www.element14.site
title: Area 
For DS
************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>   

using namespace std;

int dx[10] = {0,1,1,1,0,0,0,-1,-1,-1};
int dy[10] = {0,-1,0,1,-1,0,1,-1,0,1};
char s[1000010];
long long area,x,y,px,py;

int main()
{
	int num, len;
	scanf("%d", &num);

	while (num--) {
		scanf("%s", s);
		len = strlen(s);

		if (len < 3) {
			printf("0\n");
			continue;
		}
		
		area = 0;
		x = y = 0;

		for (int i = 0; i < len - 1; i++) {
			px = x + dx[s[i] - '0'];
			py = y + dy[s[i] - '0'];
			area += (px*y - x*py);
			x = px;
			y = py;
		}

		if (area < 0) area = area * (-1);
		printf("%lld", area/2);
		if (area % 2) printf(".5");
		printf("\n");
	}
	
}

