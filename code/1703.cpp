#include<iostream>
using namespace std;
int a[1001][1001],vst[1001]={0},n,m,s=0;
void dfs(int i)
{
	vst[i]=1;
	for(int j=1;j<=n;j++)
		if(a[i][j]==1&&vst[j]==0)dfs(j);
}
int main()
{
	int x,y,s=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){cin>>x>>y;a[x][y]=1;a[y][x]=1;}
	for(int i=1;i<=n;i++)
		if(vst[i]==0){dfs(i);s++;}
	cout<<s<<endl;
	return 0;
}