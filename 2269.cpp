#include<iostream>
#include<cstring>
using namespace std;
int n,map[1001][1001]={0},vst[1001]={0},t=0,ans=0,d[1001]={0},rd[1001]={0};
void dfsone(int x)
{
	vst[x]=1;
	for(int i=1;i<=n;i++)if(!vst[i]&&map[x][i])dfsone(i);
	d[++t]=x;
} 
void dfstwo(int x)
{
	vst[x]=t;
	for(int i=1;i<=n;i++)if(!vst[i]&&map[i][x])dfstwo(i);
}
void kosaraju()
{
	for(int i=1;i<=n;i++)if(!vst[i])dfsone(i);
	memset(vst,0,sizeof(vst));
	t=0;
	for(int i=n;i>=1;i--)if(!vst[d[i]]){t++;dfstwo(d[i]);}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(map[i][j]&&vst[i]!=vst[j])rd[vst[j]]++;
	for(int i=1;i<=t;i++)
		if(!rd[i])ans++;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		cin>>map[i][j];
	kosaraju();
	cout<<ans<<endl;
	return 0;
}
/*
8
0 0 1 0 0 0 0 0 
1 0 0 1 0 0 0 0 
0 1 0 1 1 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 1 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 1 0 0 0 1
0 0 0 0 0 0 1 0
*/