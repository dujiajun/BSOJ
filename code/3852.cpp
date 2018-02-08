#include<iostream>
#include<algorithm>
using namespace std;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct queue{int x,y,t;}q[250005];
struct point{int x,y;}p[250005];
int n,m,a,b,vst[505][505],t,ti[505][505];
void bfs()
{
	int l=1,r=t;int x,y,nx,ny;
	while(l<=r)
	{
		x=q[l].x;y=q[l].y;
		for(int i=0;i<=3;i++)
		{
			nx=x+dx[i];ny=y+dy[i];
			if(vst[nx][ny]!=1&&nx>=1&&nx<=n&&ny>=1&&ny<=m&&ti[nx][ny]>ti[x][y]+1)
			{
				r++;
				q[r].x=nx;
				q[r].y=ny;
				ti[nx][ny]=ti[x][y]+1;
				vst[nx][ny]=1;
			}
		}
		l++;
	}
}
int main()
{
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)ti[i][j]=1<<29;
	for(int i=1,x,y;i<=a;i++)
	{
		scanf("%d%d",&x,&y);
		ti[x][y]=0;
		t++;
		q[t].x=x;
		q[t].y=y;
		q[t].t=0;
	}
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		vst[p[i].x][p[i].y]=2;
	}
	bfs();
	for(int i=1;i<=b;i++)printf("%d\n",ti[p[i].x][p[i].y]); 
	return 0;
}
/*
5 4 2 3
1 1
5 4
3 3
5 3
2 4
*/