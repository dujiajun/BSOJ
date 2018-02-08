#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[1001][2]={0},vst[1001]={0},my[1001]={0};
int dfs(int x)
{
	for(int i=0;i<=1;i++)
	{
		int k=a[x][i];
		if(!vst[k])
		{
			vst[k]=1;
			if(!my[k]||dfs(my[k]))
			{
				my[k]=x;
				return 1;
			}
		}
	}
	return 0; 
}
int main()
{
	cin>>n>>m;
	for(int i=1,x;i<=m;i++)cin>>a[i][0]>>a[i][1];
	int ans=0;
	for(int i=1,x;i<=m;i++)
	{
		memset(vst,0,sizeof(vst));
		if(dfs(i))ans++;
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 6 
3 2
2 0 
0 3 
0 4
3 2
3 2
*/