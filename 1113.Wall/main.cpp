/************************
author: wfnuser date www.element14.site
title: Wall
For DS
************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

#define pi acos(-1.0)
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)  

struct point { int x, y; };
point p[1005];
int stack[1005], top;

double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross(point p0, point p1, point p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool cmp(point p1, point p2) {
    int tmp = cross(p[0], p1, p2);
    if (tmp > 0) return true;
    else if (tmp == 0 && dis(p[0],p1)<dis(p[0],p2)) return true;
    else return false;
}

void init(int n) {
    int i,k;
    point p0;
    scanf("%d%d", &p[0].x, &p[0].y);
    p0.x = p[0].x;
    p0.y = p[0].y;
    k = 0;
    for (i = 1; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        if (p0.y > p[i].y || (p0.y == p[i].y && p0.x > p[i].x))
        {
            p0.x = p[i].x;
            p0.y = p[i].y;
            k = i;
        }
    }
    p[k] = p[0];
    p[0] = p0;

    sort(p+1,p+n,cmp);
}

void graham (int n) {
    int i;
    if (n == 1) {top = 0; stack[0] = 0;}
    if (n == 2) {
        top = 1;
        stack[0] = 0;
        stack[1] = 1;
    }
    if (n > 2) {
        for (i = 0; i <= 1; i++) stack[i] = i;
        top = 1;
        for (i = 2; i < n; i++) {
            while (top > 0 && cross(p[stack[top-1]],p[stack[top]],p[i]) <= 0) top--;
            top++;
            stack[top] = i;
        }
    }
}

int main()
{
    int N,L;

    scanf("%d%d", &N, &L);
    init(N);
    graham(N);
    double res = 0;
    for (int i = 0; i < top; i++) {
        res += dis(p[stack[i]], p[stack[i+1]]);
    }
    res += dis(p[stack[0]], p[stack[top]]);

    res += 2*pi*L;
    printf("%d\n", (int) (res + 0.5));
    return 0;
}

