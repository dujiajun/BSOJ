#include<iostream>
using namespace std;
int main()
{
	int n,p,ans=0;
   	while(cin>>n)
    {  
		p=5;ans=0;
       	while(n>=p){ans+=n/p;p*=5;}
       	cout<<ans<<endl;
    }
    return 0;
}