#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[20000];
int n,m,cnt=1,h[10010]={0},my[10010]={0},s[10010][300]={-1},s0[10010]={0},fa[10010]={0},ans=0,v[10010]={0},vst[10010]={0};
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
int dfs(int x)
{
	v[x]=1;
	for(int i=h[x];i;i=a[i].next)
	{
		int to=a[i].to;
		if(!vst[to])
		{
			vst[to]=1;
			for(int k=s0[to];k<ans;k++)
			if(s[to][k]==-1||(!v[s[to][k]]&&dfs(s[to][k]))){s[to][k]=x;s0[to]=k+1;fa[x]=to;return 1;}
			for(int k=0;k<s0[to];k++)
			if(s[to][k]==-1||(!v[s[to][k]]&&dfs(s[to][k]))){s[to][k]=x;fa[x]=to;return 1;}
		}
	}
	return 0;
}
bool check()
{
	for(int i=1;i<=m;i++)
	if(fa[i]==0)
	{
		memset(v,0,sizeof(v));
		memset(vst,0,sizeof(vst));
		if(!dfs(i))return 0;
	}
	return 1;
}
void solve()
{
	memset(s0,0,sizeof(s0));
	memset(s,-1,sizeof(s));
	memset(fa,0,sizeof(fa));
	for(ans=0;;ans++)if(check())break;
	cout<<ans<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		add(i,y);
		add(i,x);
	}
	solve();
	return 0;
}
/*
4 4
1 2
1 3
1 4
1 2
*/