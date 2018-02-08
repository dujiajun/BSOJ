#include<iostream>
#include<cstring>
using namespace std;
int n,m,map[101][101],dx[]={1,0,-1,0},dy[]={0,1,0,-1},ans=0;
bool vst[101][101]={0},used[101][101]={0};
struct nd{int x,y;}q[10001];
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>map[i][j];	
}
void bfs(int x,int y)
{
	if(x==1||y==1||x==n||y==m)
	{
		vst[x][y]=1;
		return;
	}
	memset(q,0,sizeof(q));
	memset(used,0,sizeof(used));
	int head=1,tail=1,minn=0x7fffffff,nx,ny,sum=map[x][y];;
	q[head].x=x;q[head].y=y;
	used[x][y]=1;
	while(head<=tail)
	{	
		for(int i=0;i<4;i++)
		{
			nx=q[head].x+dx[i];ny=q[head].y+dy[i];
			if(map[nx][ny]<=map[x][y]&&!used[nx][ny])
			{
				tail++;
				q[tail].x=nx;
				q[tail].y=ny;
				if(nx==1||nx==n||ny==1||ny==m)return;
				sum+=map[nx][ny];
			}
			else if(minn>map[nx][ny]&&!used[nx][ny])minn=map[nx][ny];
			used[nx][ny]=1;
		}
		head++;
	}
	for(int i=1;i<=tail;i++)
	{
		vst[q[i].x][q[i].y]=1;
		map[q[i].x][q[i].y]=minn;
	}
	ans+=minn*tail-sum;
}
void solve()
{
	for(int i=2;i<n;i++)
	for(int j=2;j<m;j++)
	if(vst[i][j]==0)bfs(i,j);
	cout<<ans<<endl;	
}
int main()
{
	init();
	solve();
	return 0;
}