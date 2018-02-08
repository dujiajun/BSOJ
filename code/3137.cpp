#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct que{int x,y;}q[1000001];
int n,m,map[1001][1001]={0},maxx=0,vst[1001][1001]={0},dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
void bfs(int num)
{
	int l=1,r=1,x,y,nx,ny;
	q[1].x=1;q[1].y=1;vst[1][1]=1;
	while(l<=r)
	{
	  	x=q[l].x,y=q[l].y;
	  	for(int i=0;i<=3;i++)
	  	{
	  	  	nx=x+dx[i],ny=y+dy[i];
	  	  	if(!vst[nx][ny]&&map[nx][ny]<=num&&nx>=1&&nx<=n&&ny>=1&&ny<=m)
	  	  	{
	  	  	  	r++;
	  	  	  	q[r].x=nx;q[r].y=ny;
				vst[nx][ny]=1;
	  	  	}
	  	}
	  	l++;
	}
}
bool check(int x)
{
	memset(vst,0,sizeof(vst));
	bfs(x);
	for(int i=1;i<=m;i++)if(vst[n][i]==0)return false;
	return true;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
	    scanf("%d",&map[i][j]);
	    maxx=max(maxx,map[i][j]);
	}
	int l=1,r=maxx;
	while(l<r)
	{
		int mid=(l+r)/2;
	  	if(check(mid))r=mid;
	  	else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}