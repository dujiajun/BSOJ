#include<iostream>
#include<cstring> 
using namespace std;
int n,m,lim[100]={0},dp[15][4]={0},len=0;
void tostring(int x)
{
	len=0;
	while(x){lim[++len]=x%10;x/=10;}
}
int dfs(int i,int j,int bj)
{
	if(i==1)return 1;
	if(!bj&&dp[i][j]!=-1)return dp[i][j];
	int up=bj?lim[i-1]:9,ret=0;
	for(int k=0;k<=up;k++)
	{
		if(k==4)continue;
		if(j==1&&k==2)continue;
		ret+=dfs(i-1,k==6?1:0,bj&&k==up);
	}
	return bj?ret:dp[i][j]=ret;
}
int main()
{
	while(1)
	{
		cin>>n>>m;
		if(n==0&&m==0)break;
		memset(lim,0,sizeof(lim));
		tostring(n-1);
		memset(dp,-1,sizeof(dp));
		int t1=dfs(len+1,0,1);
		memset(lim,0,sizeof(lim));
		tostring(m);
		memset(dp,-1,sizeof(dp));
		int t2=dfs(len+1,0,1);
		cout<<t2-t1<<endl;
	}
	return 0;
}