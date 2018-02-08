#include<iostream>
#include<cmath>
using namespace std;
int n,num,minn=1<<20,a[25],sum;
void dfs(int x,int dp)
{
	if(dp==n+1){minn=min(minn,abs(sum-num*2));return;}
	for(int i=x;i<=n;i++)
	{
		num+=a[i];
		minn=min(minn,abs(sum-num*2));
		dfs(i+1,dp+1);
		num-=a[i];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	dfs(1,1);  
	cout<<minn;
	return 0;
}
/*
5
5
8
13
27
14
*/