#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int map[4][4];
int minflip=100;

void flip(int row, int col)
{
	int dx[5] = {0,0,0,1,-1};
	int dy[5] = {0,1,-1,0,0};
	int r,c;

	for(int i=0;i<=4;i++){
		r = row + dx[i];
		c = col + dy[i];
		if(r<4&&c<4&&r>=0&&c>=0)	
			map[r][c] = !map[r][c];
	}
}

void printmap()
{
	//cout<<"############"<<endl;
	for(int i=0; i<=3; i++){
		for(int j=0; j<=3; j++){
			//cout<<map[i][j];
		}
		//cout<<endl;
	}
	//cout<<"###########"<<endl;
	//cout<<endl;
}

bool check()
{
	int temp = map[0][0];
	for(int i = 0; i <= 15; i++)
		if(map[i/4][i%4] != temp) return false;
	return true;
}

void dsp(int step, int flipnum)
{
	if(check()){
		//cout<<endl<<"Success!"<<endl; 
		if(flipnum<minflip) minflip = flipnum;
		return;
	}
	if(step == 16) return;

	int row = step / 4;
	int col = step % 4;
	
	step++;
	
	//cout<<endl;
	//cout<<row<<" "<<col<<endl;
	flip(row,col);
	flipnum++;
	printmap();
	//cout<<endl;
	dsp(step,flipnum);
	
	//cout<<endl;
	//cout<<row<<" "<<col<<endl;
	flip(row,col);
	flipnum--;
	printmap();
	//cout<<endl;
	dsp(step,flipnum);
	
}

int main()
{
	char ch;
	for(int i=0; i<=3; i++)
		for(int j=0; j<=3; j++){
			cin>>ch;
			map[i][j] = (ch == 'w') ? 1 : 0;
		}
	printmap();
	dsp(0,0);

	if(minflip >= 16) cout<<"Impossible";
	else cout<<minflip;

}

