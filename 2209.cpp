#include<iostream>
#include<xinyue>
using namespace std;
int n,m,h=1,t=1,a,ans=-0x7fffffff,q[200001],sum[200001],num[200001];
int main()
{
	xin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		xin>>a;
		sum[i]=sum[i-1]+a;
		ans=max(ans,sum[i]-q[h]);
		while(q[t]>=sum[i]&&t>0)t--;
		q[++t]=sum[i];
		num[t]=i;
		while(num[h]<=i-m)h++;
	}
	yue<<ans;
	return 0;
}