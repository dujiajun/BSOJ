#include<iostream>
#include<cstring>
using namespace std;
int n,m,k,vst[600]={0},a[600][600]={0},my[600]={0};
int dfs(int x)
{
	for(int i=1;i<=n;i++)
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
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
	}
	solve();
	return 0;
}
/*
3 4
1 1
1 3
2 2
3 2
*/