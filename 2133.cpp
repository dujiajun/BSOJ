#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[300][300]={0},vst[300]={0},bl[300]={0};
int dfs(int x)
{
	for(int i=1;i<=m;i++)
	if(a[x][i]==1&&!vst[i])
	{
		vst[i]=1;
		if(bl[i]==0||dfs(bl[i]))
		{
			bl[i]=x;
			return 1;
		}
	}
	return 0;
}
int xiong()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		if(dfs(i))ans++;
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1,s,x;i<=n;i++)
	{
		cin>>s;
		for(int j=1;j<=s;j++)
		{
			cin>>x;
			a[i][x]=1;
		}
	}
	cout<<xiong()<<endl;
	return 0;
}
/*
5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2 
*/