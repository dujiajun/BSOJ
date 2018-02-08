#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[2000005],ans,q[2000005],h,t;
long long sum[2000005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[n+i]=a[i];
	}
	for(int i=1;i<=n+n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		while(h<t&&sum[q[t-1]]>=sum[i])t--;
		q[t++]=i;
	}
	//if(sum[q[h]]>=0)ans++;
	for(int i=n+1;i<=n+n;i++)
	{
		while(h<t&&(q[h]<=i-n))h++;
		while(h<t&&sum[q[t-1]]>=sum[i])t--;
		q[t++]=i;
		if(sum[q[h]]-sum[i-n]>=0)ans++;
	}
	cout<<ans<<endl;
	return 0;
}