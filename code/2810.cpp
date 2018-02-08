#include<iostream>
#include<cstring>
using namespace std;
struct wd{int l,r;}q[2500005];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,a[600][600]={0},vst[600][600]={0},cnt=0;
void dfs(int x,int y)
{
	vst[x][y]=1;
	for(int i=0,nx,ny;i<=3;i++)
	{
		nx=x+dx[i];ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vst[nx][ny]&&a[x][y]>a[nx][ny])
		dfs(nx,ny);
	}
}
int figure()
{
	int ans=0;
	for(int i=1;i<=m;i++)if(!vst[1][i])dfs(1,i);
	for(int i=1;i<=m;i++)if(!vst[n][i])ans++;
	if(ans==0){cout<<1<<endl;return 1;}
	else {cout<<0<<endl<<ans<<endl;return 0;}
}
void find()
{
	for(int i=1;i<=m;i++)
	{
		memset(vst,0,sizeof(vst));
		dfs(1,i);
		for(int j=1;j<=m;j++)
		if(vst[n][j])
		{
			q[++cnt].l=j;
			int ed=j;
			while(vst[n][ed+1])ed++;
			q[cnt].r=ed;
			break;
		}
	}
}
void getans()
{
	int ans=0,t=0;
	for(int i=0;i<cnt;)
	{
		if(q[i].r==m)break;
		ans++;
		int r=t;
		while(q[i+1].l<=t+1&&i+1<=cnt)
		{
			if(q[i+1].r>r)r=q[i+1].r;
			i++;
		}
		t=r;
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)cin>>a[i][j];
	if(figure())
	{
		find();
		getans();
	}
	return 0;
}
/*
2 5
9 1 5 4 3
8 7 6 1 2
*/