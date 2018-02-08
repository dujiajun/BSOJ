#include<iostream>
using namespace std;
int main()
{
	long long n,p,k,t;
	cin>>n>>p>>k;t=n;n=1;
	while(p)
	{
		if(p%2)n=n*t%k;
		t=t*t%k;
		p/=2;
	}
	cout<<n<<endl;
	return 0;
}