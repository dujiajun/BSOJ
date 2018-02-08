#include<iostream>
using namespace std;
struct node{int x,y;}nc[10005];
int a[105][105],n,m,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},sum=0;
int b[105][105]={0};
void bfs(int x,int y)
{
	int head=1,tail=1,nx,ny;
	nc[1].x=x;nc[1].y=y;
	while(head<=tail)
	{
		for(int i=0;i<4;i++)
		{
			nx=nc[head].x+dx[i];ny=nc[head].y+dy[i];
			if(nx>0&&nx<=m&&ny>0&&ny<=n&&b[nx][ny]==0&&a[nx][ny]!=0)
			{
				tail++;
				nc[tail].x=nx;
				nc[tail].y=ny;
				b[nx][ny]=1;
			}
		}
		head++;
	}
}
void init()
{
	cin>>m>>n;
	char tmp;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>tmp;
		a[i][j]=tmp-'0';
	}
}
int main()
{
	init();
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	if(a[i][j]!=0&&b[i][j]==0){sum++;bfs(i,j);}
	cout<<sum;
	return 0;
}
/*
0234500067
1034560500
2045600671
0000000089
*/ 