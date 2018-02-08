#include<iostream>
using namespace std;
int map[1000][1000]={0},n,m,wh=0,vst[10000]={0};
bool dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(map[x][i]==1&&i==wh)return true;
		if(map[x][i]==1&&vst[i]==0)
		{
			vst[i]=1;
			if(dfs(i))return true;
		}
	}
	return false;
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)vst[j]=0;
		vst[i]=1;wh=i;
		if(dfs(i))cout<<"T"<<endl;
		else cout<<"F"<<endl;
	}
}
void init()
{
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		map[x][y]=1;
	}
}
int main()
{
	init();
	solve();
	return 0;
}
/*
4 6
1 2
2 3
4 1
3 1
1 3
2 3
*/