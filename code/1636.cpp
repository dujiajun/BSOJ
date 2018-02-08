#include<iostream>
using namespace std;
int vst[21]={0},a[21]={0},n,m,t=0;
void dfs(int dp)
{
	if(dp==n){t++;if(t==m){for(int i=1;i<=n;i++)cout<<a[i]<<" ";exit(0);}}
	for(int i=1;i<=n;i++)
	if(!vst[i])
	{
		vst[i]=1;
		a[dp+1]=i;
		dfs(dp+1);
		vst[i]=0;
	}
}
int main()
{
	cin>>n>>m;
	dfs(0);
	return 0;
}