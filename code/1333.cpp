#include<iostream>
using namespace std;
long long n,k,ans;
int main()
{
	while(cin>>n)
	{	
	    ans=1;k=1;
		for(int i=2;i<=n;i++)
		{	
		    k*=i;
			while(k%10==0)k/=10;
			k%=1000000;
			ans+=k%10;
		}
		cout<<ans<<endl;
	}
	return 0;	
}