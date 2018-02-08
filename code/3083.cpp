#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
long long l,r,k,i;
int t,ans;
long long change(long long x)
{
	long long tmp=0;
	while(x)
	{
		tmp=tmp+x%10;
		x/=10;
	}
	return tmp;
}
void solve()
{
	cin>>l>>r>>k;ans=0;
	l=min(l,50000ll);r=min(r,50000ll);
	for(i=l;i<=r;i++)if((change(i)*k)%i==0)ans++;
	cout<<ans<<endl;
}
int main()
{
	cin>>t;
	while(t--)solve();
	return 0;
}