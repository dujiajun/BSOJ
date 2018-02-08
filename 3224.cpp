#include<iostream>
#include<cmath>
using namespace std;
long long n,a,ans;
int main()
{
	cin>>n;
	ans=n;
	for(int i=2;i*i<=n;i++)
	if(n%i==0)
	{
		a=0;
		while(n%i==0){a++;n/=i;}
		ans+=ans*a*(i-1)/i;
	}
	if(n!=1)ans+=ans*1*(n-1)/n;
	cout<<ans<<endl;
	return 0;
}