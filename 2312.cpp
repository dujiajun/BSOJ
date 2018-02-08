#include<iostream>
#include<cstring>
using namespace std;
int n,m,k,vst[101]={0},a[101][101]={0},my[101]={0};
int dfs(int x)
{
	for(int i=1;i<=m;i++)
	if(a[x][i]&&!vst[i])
	{
		vst[i]=1;
		if(!my[i]||dfs(my[i]))
		{
			my[i]=x;
			return 1;
		}
	}
	return 0;
}
void solve()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		if(dfs(i))ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1,j,x,y;i<=k;i++)
	{
		cin>>j>>x>>y;
		a[x][y]=1;
	}
	solve();
	return 0;
}
/*
5 5 10
0 1 1
1 1 2
2 1 3
3 1 4
4 2 1
5 2 2
6 2 3
7 2 4
8 3 3
9 4 3
*/