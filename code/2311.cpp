#include<iostream>
#include<cstring>
using namespace std;
int n,m,cnt1=0,cnt2=0;
int map[205][205]={0},f[10005][1005]={0},c1[205][205]={0},c2[205][205]={0},vst[40005]={0},my[40005]={0}; 
void build()
{
	for(int i=1;i<=max(n,m);i++)map[i][0]=map[0][i]=2;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(map[i][j-1]!=2)c1[i][j]=cnt1;
	else c1[i][j]=++cnt1;	
	for(int j=1;j<=m;j++)
	for(int i=1;i<=n;i++)
	if(map[i-1][j]!=2)c2[i][j]=cnt2;
	else c2[i][j]=++cnt2;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(!map[i][j])f[c1[i][j]][++f[c1[i][j]][0]]=c2[i][j];
}
bool dfs(int x)
{
	for(int i=1;i<=f[x][0];i++)
	if(!vst[f[x][i]])
	{
		vst[f[x][i]]=1;
		if(!my[f[x][i]]||dfs(my[f[x][i]]))
		{
			my[f[x][i]]=x;
			return 1;
		}
	}
	return 0;
}
void solve()
{
	int ans=0;
	for(int i=1;i<=cnt1;i++)
	{
		memset(vst,0,sizeof(vst));
		if(dfs(i))ans++;
	}
	cout<<ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)cin>>map[i][j];
	build();
	solve();
	return 0;
 }
/*
3 4
2 0 0 0	
2 2 2 1	
0 1 0 2
*/