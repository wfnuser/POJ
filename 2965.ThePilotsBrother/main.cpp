#include<iostream>
#include<cstdlib>

using namespace std;

int map[4][4];
int path[18][2];
int final[18][2];
int mintime = 100;

bool check()
{
	for(int i=0; i<=15; i++)
		if(map[i/4][i%4] == 1) return false;
	return true;
}


void printmap(int times)
{
	for(int i = 0; i <= 15; i++){
		if(i%4 == 0) cout<<endl;
		cout<<map[i/4][i%4]<<" ";
	}
	cout<<endl;
	for(int i = 1; i <= times; i++)
		cout<<"("<<path[i][0]<<","<<path[i][1]<<") ";
	cout<<endl;
	cout<<"########end########"<<endl<<endl<<endl;
}

void handle(int row, int col, int times)
{
	map[row][col] = !map[row][col];
	for(int i = 0; i <= 3; i++){
		map[i][col] = !map[i][col];
		map[row][i] = !map[row][i];
	}
}

void dfs(int steps, int times)
{
	int row, col;

	if(check()){
		if(mintime > times){ 
			mintime = times;
			for(int i = 1; i <= times; i++){
				final[i][0] = path[i][0];
				final[i][1] = path[i][1];
			}
		}	
		return;
	}
	if(steps>=16) return;
	
	row = steps / 4;
	col = steps % 4;
	steps++;
	times++;
	handle(row,col,times);
	path[times][0] = row;
	path[times][1] = col;
	dfs(steps, times);
	times--;
	handle(row,col,times);
	dfs(steps, times);	
}

int main()
{
	char ch;
	for(int i=0; i<=3; i++){
		for(int j=0; j<=3; j++){
			cin>>ch;
			map[i][j] = (ch == '+') ? 1 : 0 ;			
		}
	}
	dfs(0,0);
	cout<<mintime<<endl;
	for(int i=1; i<=mintime; i++){
		cout<<final[i][0]+1<<" "<<final[i][1]+1<<endl;
	}
}

