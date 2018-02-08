#include<iostream>
using namespace std;
int n,k,c[15][5005]={0},bj=1;
void pre()
{
	c[0][1]=1;
	for(int j=1;j<=5000;j++)
	for(int i=0;i<=10;i++)
	{
		if(i==0)c[i][j]=1;
		else c[i][j]=c[i-1][j-1]+c[i][j-1];
		if(c[i][j]>10000000)c[i][j]=10000000;
	}
}
void solve(int nn,int kk,int mm)
{
	if(kk==0&&mm==1)return;
	if(kk==0||c[kk][mm-1]>=nn)
	{
		if(!bj)cout<<0;
		solve(nn,kk,mm-1);
	}
	else 
	{
		bj=0;
		cout<<1;
		solve(nn-c[kk][mm-1],kk-1,mm-1);
	}
}
int main()
{
	cin>>n>>k;
	if(k==1)//Special Judge Here
	{
		cout<<1;
		for(int i=1;i<n;i++)cout<<0;
		return 0;
	}
	pre();
	solve(n,k,5000);
	return 0;
}