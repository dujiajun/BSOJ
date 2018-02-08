#include<iostream>
using namespace std;
int n,v[50]={0},f[50][50]={0},p[50][50]={0};
int dp(int i,int j)
{
	if(i>j)return 1;
	if(i==j)return v[i];
	if(f[i][j]>0)return f[i][j];
	for(int k=i;k<=j;k++)
		if(dp(i,k-1)*dp(k+1,j)+v[k]>f[i][j])
		{
			f[i][j]=dp(i,k-1)*dp(k+1,j)+v[k];
			p[i][j]=k;
		}
	return f[i][j];
}
void output(int i,int j)
{
	if(i>j)return ;
	if(i==j){cout<<i<<" ";return ;}
	cout<<p[i][j]<<" ";
	output(i,p[i][j]-1);
	output(p[i][j]+1,j);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	cout<<dp(1,n)<<endl;
	output(1,n);
	return 0;
}