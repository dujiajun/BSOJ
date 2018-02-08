#include<iostream>
#include<cmath>
using namespace std;
int x,y,p,q,ans=0,t,j;
int gcd(int a,int b){if(a%b==0)return b;else return gcd(b,a%b);}
int main()
{
 	cin>>x>>y;
 	if(y%x!=0){cout<<0;return 0;}
 	if(y==x){cout<<1;return 0;}
 	y/=x;t=sqrt(y);
 	for(int i=1;i<=t;i++)
 	{
 		
 		if(y%i==0)
	 	{
		 	j=y/i;
		 	if(gcd(i,j)==1)ans+=2;
 		}
 	}
 	cout<<ans;
	return 0;
}
