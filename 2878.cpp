#include<iostream>
using namespace std;
bool a[210][210],vst[210];
int n,m,ans=0;
void dfs(int i)
{
	ans++;
	vst[i]=1;
	for(int j=1;j<=n;j++)
		if(vst[j]==0&&a[i][j]==1)dfs(j);
}
int main()
{
	cin>>n>>m;
	int x,y,st;
	for(int i=1;i<=m;i++){cin>>x>>y;a[x][y]=1;}
	cin>>st;
	dfs(st);
	cout<<ans<<endl;
	return 0;
}
/*
5 8
3 5
4 5
4 3
2 3
5 4
4 1
4 2
2 4
1
*/