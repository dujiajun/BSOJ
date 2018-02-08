#include<iostream>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
long long f[2005][2005]={0};
int n,h,a[2005];
int main()
{
	cin>>n>>h;a[0]=h;a[n+1]=h;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(abs(a[i]-a[i-1])>=2)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	f[1][0]=(a[1]==h||a[1]+1==h);
	f[1][1]=(a[1]+1==h);
	for(int i=2;i<=n;i++)
	for(int j=max(0,h-a[i]-1);j<=min(i,h-a[i]);j++)
	{
		if(a[i]+j+1==h)
		{
			f[i][j]=(f[i][j]+f[i-1][j+1]*(j+1)%MOD)%MOD;
			f[i][j]=(f[i][j]+f[i-1][j]*j%MOD)%MOD;
			f[i][j]=(f[i][j]+f[i-1][j])%MOD;
		}
		if(a[i]+j==h)
		{
			f[i][j]=(f[i][j]+f[i-1][j-1])%MOD;
			f[i][j]=(f[i][j]+f[i-1][j])%MOD;
		}
	}
	cout<<f[n][0]<<endl;
	return 0;
}