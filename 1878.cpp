#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,mid,dis[10000001]={0};//40M
bool check(int x)
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
	  	if(dis[i]-t<0)return false;
	  	if(dis[i]-t>m)t+=dis[i]-t-m;
	  	t+=x;
	}
	return true;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&dis[i]);
	sort(dis+1,dis+n+1);
	int l=1,r=dis[2];
	while(1)
	{
	  	mid=(l+r)/2;
	  	if((r-l)<=1)break;
	  	if(check(mid))l=mid;
	  	else r=mid;
	}
	cout<<mid;
	return 0;
}

/*
6 100
236
120
120
120
120
120
*/