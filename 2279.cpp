#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,map[101][101]={0},c[101][101]={0},ans=0,num[101]={0};
int dfs(int x)
{
	if(num[x])return num[x];
	num[x]=1;
	for(int i=1;i<=n;i++)
	if(map[x][i])num[x]=max(num[x],dfs(i)+1);
	return num[x];
}
int main()
{
	//freopen("rank.in","r",stdin);
	//freopen("rank.out","w",stdout);
	cin>>n>>m;
	for(int i=1,a;i<=m;i++)
	for(int j=1;j<=n;j++){cin>>a;c[a][i]=j;}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j){
		int k=1;
		for(k=1;k<=m;k++)if(c[i][k]>c[j][k])break;
		if(k==m+1)map[i][j]=1;
	}
	for(int i=1;i<=n;i++){ans=max(ans,dfs(i));}
	cout<<ans<<endl;
	return 0;
}
/*
4 3
4 1 2 3
4 1 3 2
4 3 1 2
*/