#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,ans=0,map[1001][1001]={0};
bool vst[1001]={0};
void init()
{
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		map[x][y]=1;
	}
}
void dfs(int dp)
{
	vst[dp]=1;
	for(int i=1;i<=n;i++)
		if(map[dp][i]&&!vst[i]){ans++;dfs(i);}
}
int main()
{
	init();
	for(int i=1;i<=n;i++)
	{	
		memset(vst,0,sizeof(vst));
		dfs(i);
	}
	ans=n*(n-1)/2-ans;
	printf("%d",ans);
	return 0;
} 