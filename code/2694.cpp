#include<iostream>
using namespace std;
int n,a[55],ans;
bool check(long long x)
{
	long long tmp=0;
	for(int i=1;i<=n;i++)
	if(a[i]<x)tmp+=x-a[i];
	return tmp<=x;
}
int main()
{
	cin>>n;n++;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long l=0,r=6*1e8,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}