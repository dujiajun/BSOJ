#include<iostream>
#include<cstdio>
using namespace std;
long long n,a1,ai,ans=0;
int main()
{
	cin>>n>>a1;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&ai);
		if(a1>ai)ans+=a1;
		else ans+=ai;
		a1=ai;
	}
	cout<<ans;
	return 0;
}