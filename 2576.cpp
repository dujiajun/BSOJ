#include<iostream>
using namespace std;
int n,m,st[16][5000]={0},num[16]={0},f[15][1000]={0},ans=0;
void getst(int i,int t)
{
	int nm=0;
	for(int j=0;j<(1<<m);j++)
	if(j&(j<<1)||j&(j>>1)||j&t)continue;
	else st[i][++nm]=j;
	num[i]=nm;
}
int main()
{
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)
	{
		int t=0;
		for(int j=1;j<=m;j++){cin>>x;t=(t<<1)+1-x;}
		getst(i,t);
	}
	for(int i=1;i<=num[1];i++)f[1][i]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<=num[i];j++)
	for(int k=1;k<=num[i-1];k++)
	{
		if(st[i][j]&st[i-1][k])continue;
		f[i][j]+=f[i-1][k];
	}
	for(int i=1;i<=num[n];i++)ans=(ans+f[n][i])%100000000;
	cout<<ans<<endl;
	return 0;
}
/*
2 3
1 1 1
0 1 0
*/