#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n,maxx=0,t;
	cin>>n;t=sqrt(n);
	for(long long i=2;i<=t;i++)if(n%i==0)maxx=max(maxx,i);
	cout<<n/maxx<<endl;
	return 0;	
}