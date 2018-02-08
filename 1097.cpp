#include <iostream>
using namespace std;
int r,c,n,map[250][250]={0},dir;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
string dr;char ch;
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	{
		cin>>ch;
		if(ch=='.')map[i][j]=-1;
		if(ch=='X')map[i][j]=-2;
		if(ch=='*')map[i][j]=0;
	}
	cin>>n;
	for(int k=0;k<n;k++)
	{
		cin>>dr;
		if(dr=="EAST")dir=0;
		if(dr=="SOUTH")dir=1;
		if(dr=="WEST")dir=2;
		if(dr=="NORTH")dir=3;
		for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		if(map[i][j]==k)
		{
			int t=1;
			while(1)
			{
				int nx=i+t*d[dir][1],ny=j+t*d[dir][0];
				if(ny>c||ny<=0)break;
				if(nx>r||nx<=0)break;
				if(map[nx][ny]==-2)break;
				map[nx][ny]=k+1;
				t++;
			}
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(map[i][j]==-2)cout<<"X";
			else if(map[i][j]==n)cout<<"*";
			else cout<<".";
		}
		cout<<endl;
	}
	return 0;
}
/*
3 3
...
..X
*..
3
EAST
NORTH
WEST
*/