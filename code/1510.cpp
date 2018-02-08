#include<iostream>
using namespace std;
int n,k,ans=0;
void doit()
{
	int t=1;
	while(n)
	{
		if(n%2)ans+=t;
		t*=k;
		n/=2;
	}
}
int main()
{
	cin>>k>>n;
	doit();
	cout<<ans;
	return 0;
}