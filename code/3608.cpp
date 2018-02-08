#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main()
{
	long long a,b;
	while(cin>>a>>b)printf("%lld\n",a*b/gcd(a,b));
	return 0;
} 