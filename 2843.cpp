#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
long long sum[100005],a[100005],e,tmp,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ans+=a[i];
	}
	e=ans/n;
	for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i]-e;
	sort(sum,sum+n);
	tmp=sum[(n-1)/2];ans=0;
	for(int i=0;i<n;i++)ans+=abs(tmp-sum[i]);
	cout<<ans<<endl;
	return 0;
}