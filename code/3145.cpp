#include<iostream>
#include<cstdio>
using namespace std;
int n,k,p,ans=0,cnt[220000][60]={0},f[220000]={0},c[220000]={0},v[220000]={0};
int main()
{
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
	{
	  	scanf("%d%d",&c[i],&v[i]);
	  	for(int j=0;j<k;j++)
	  	if(j==c[i])cnt[i][j]=cnt[i-1][j]+1;
	  	else cnt[i][j]=cnt[i-1][j];
	}
	for(int i=1;i<=n;i++)
	if(v[i]<=p)
	{
	    f[i]=i;
	    ans+=cnt[i-1][c[i]];
	}
	else
	{
	    f[i]=f[i-1];
	    ans+=cnt[f[i]][c[i]];
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 2 3 
0 5 
1 3 
0 2 
1 3 
1 5
*/
