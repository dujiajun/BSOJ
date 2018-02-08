#include<iostream>
using namespace std;
int n,s=0,a;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a;s^=a;}
	if(s)cout<<1;
	else cout<<2;
	return 0;
}