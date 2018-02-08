#include<iostream>
using namespace std;
void ext(long long a,long long b,long long &d,long long &x,long long &y)
{
	if(b==0){d=a;x=1;y=0;}
	else 
	{
		ext(b,a%b,d,x,y);
		long long t=x;x=y;y=t-(a/b)*y;
	}
}
int main()
{
	long long x,y,d,n,m1,a1,m2,a2,c,t;
	cin>>n;cin>>m1>>a1;
	for(int i=2;i<=n;i++)
	{
		cin>>m2>>a2;
		ext(m1,m2,d,x,y);
		c=a2-a1;
		if(c%d){cout<<-1;return 0;}
		t=(c*x/d%(m2/d)+m2/d)%(m2/d);
		a1=a1+t*m1;m1=m1*m2/d;
	}
	cout<<a1;
	return 0;
}
/*
3
3 1
5 1
7 2
*/