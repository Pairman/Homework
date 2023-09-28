#include<bits/stdc++.h>
using namespace std;
struct coordinate{
	int row=1,col=1;
}pos;

int main(){
	int n=0,m=0,history[101][101]={0},count=0; cin>>m>>n>>pos.col;
	char map[101][101]={0};
	for(int row=1;row<=m;++row){
		for(int col=1;col<=n;++col){cin>>map[row][col];}
	}

	while(1){
		if(!map[pos.row][pos.col]){cout<<"out "<<count; break;}
		if(history[pos.row][pos.col]){cout<<"loop "<<count; break;}
		history[pos.row][pos.col]=1;
		switch(map[pos.row][pos.col]){
			case 'N': --pos.row; break;
			case 'S': ++pos.row; break;
			case 'W': --pos.col; break;
			case 'E': ++pos.col; break;
		}
		++count;
	}
}