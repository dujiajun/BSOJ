#include<iostream>
#include<cmath>
using namespace std;
int n,ans;
int main()
{
	cin>>n;
	long long l=1,r=0x7fffffff,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(mid*(log(mid)/log(10))+1>=n)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}