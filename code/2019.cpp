#include<iostream>
using namespace std;
int n,k;
long long sum;
int main()
{
	cin>>n>>k;
	sum=(long long)n*k;
	n=min(n,k);
	int i=1,d;
	for(int i=1;i<=n;i=d+1)
	{
		d=min(n,k/(k/i));
		sum-=(long long)(i+d)*(d-i+1)*(k/i)/2;
	}
	cout<<sum<<endl;
	return 0;
} 