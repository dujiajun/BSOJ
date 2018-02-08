#include<iostream>
using namespace std;
int phi(int x)
{
	int ans=x,p;
	for(int i=2;i*i<=x;i++)
	if(x%i==0)
	{
		ans-=ans/i;
		while(x%i==0)x/=i;
	}
	if(x!=1)ans-=ans/x;
	return ans;
}
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)break;
		cout<<phi(n)<<endl;
	}
	return 0;
}