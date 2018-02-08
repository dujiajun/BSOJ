#include<iostream>
using namespace std;
const int INF=0x7fffffff/2;
int map[300][300]={0},n,m,g[300][300]={0},sum=0,ans=0;
void init()
{
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)map[i][j]=map[j][i]=INF;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		map[a][b]=map[b][a]=1;
	}
}
void solve()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
		if(map[i][k]+map[k][j]==map[i][j]&&map[i][k]==1)g[i][j]++;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		sum=0;
		for(int k=1;k<=n;k++)
		if(map[i][k]+map[k][j]==map[i][j])sum+=g[k][j];
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}