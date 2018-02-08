#include<iostream>
using namespace std;
struct nd{int x,y;}q[40000]={0};
int a[200][200],b[200][200]={0},n,m,s=0,t=0,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs()
{
	int nx,ny;
	while(s<=t)
	{
		for(int i=0;i<4;i++)
		{
			nx=q[s].x+dx[i];ny=q[s].y+dy[i];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&!b[nx][ny])
			{
				b[nx][ny]=1;
				t++;
				q[t].x=nx;q[t].y=ny;
				a[nx][ny]=a[q[s].x][q[s].y]+1;
			}
		}
		s++;
	}
}
int main()
{
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>ch;
		if(ch=='1')
		{
			t++;
			q[t].x=i;q[t].y=j;
			a[i][j]=0;b[i][j]=1;
		}
	}
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}