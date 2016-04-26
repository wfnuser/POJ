#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>

using namespace std;


struct graph {
	typedef vector<int> VI;
	VI info, next, to;
	graph(int n=0, int m=0) : to(0), next(0) {
		info.resize(n);
		next.reserve(m);
		to.reserve(m);
	}
	
	int edge_size() {
		return to.size();
	}
	
	int vertex_size() {
		return to.size();
	}
	
	void expand(int i) {
		if (info.size() < i + 1)
			info.resize(i+1);
	}
	
	void add(int i, int j) {
		expand(i),expand(j);
		to.push_back(j);
		next.push_back(info[i]);
		info[i] = to.size() - 1;
	}

	void del_back() {
		int i;
		for(i = 0; i < info.size(); i++)
			if(info[i] == to.size() - 1){
				info[i] = next.back();
				break;
			}
		to.pop_back();
		next.pop_back();
	}

	void clear() {
		info.clear();
		next.resize(0);
		to.resize(0);
	}
};

graph G;

int main()
{
	int n;
	cin>>n;

	for(int i=1; i<=n; i++){
		int dst;
		
		while(cin>>dst){
			if(dst == 0) break;
			G.add(1,dst);
		}

	}	
}
