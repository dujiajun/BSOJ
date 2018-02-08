#include<iostream>
using namespace std;
long long n,x1=1,y1,x;
long long gcd(long long a,long long b)
{
	if(b>a)swap(a,b);
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main()
{
	cin>>n;cin>>x1;y1=x1;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		x1=gcd(x1,x);
		y1=x*y1/gcd(x,y1);
	}
	cout<<x1<<endl<<y1;
	return 0;
}