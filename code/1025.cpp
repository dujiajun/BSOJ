#include<iostream>
using namespace std;
int main()
{   
	long long n,m=1,k;
    cin>>n;
	if(n==1){cout<<1;return 0;}
    for(int i=1;i<=n;i++)
	{
	    k=i;
	    while(k%10==0)k/=10;
	    m*=k;
	    while(m%10==0)m/=10;
	    m%=1000000;
	}
	while(m%10==0)m/=10;
	m%=10;
	cout<<m;
	return 0;
}