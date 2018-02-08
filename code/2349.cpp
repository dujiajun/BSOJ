#include<iostream>
using namespace std;
int m,n,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},nx,ny;
int a[15][15],sum=0,sx,sy,ex,ey;
void dfs(int x,int y)
{
	if(x==ex&&y==ey){sum++;return;}
	for(int i=0;i<4;i++)
	{
		nx=x+dx[i];ny=y+dy[i];
		if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&a[nx][ny])
		{
			a[x][y]=0;
			dfs(nx,ny);
			a[x][y]=1;
		}
	}
}

int main()
{
	
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)cin>>a[i][j];
	cin>>sx>>sy>>ex>>ey;
	a[sx][sy]=0;
	dfs(sx,sy);
	if(sum==0)cout<<-1<<endl;
	else cout<<sum<<endl;
	return 0;
}