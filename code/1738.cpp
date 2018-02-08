#include<iostream>
using namespace std;
int n,a[101],b[101];
void ext(long long a,long long b,long long &d,long long &x,long long &y)
{
	long long t;
	if(b==0){d=a;x=1;y=0;}
	else 
	{
		ext(b,a%b,d,x,y);
		t=x;x=y;y=t-(a/b)*y;
	}
}
int main()
{
	long long x,y,d,m=1,m1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		m*=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		m1=m/a[i];
		ext(m1,a[i],d,x,y);
		ans=(ans+m1*x*b[i])%m;
	}
	cout<<(ans+m)%m;
	return 0;
}