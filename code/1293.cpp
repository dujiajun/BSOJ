#include<iostream>
using namespace std;
int n,a,b,ta,tb;
int main()
{
	cin>>n>>a>>b;ta=a,tb=b;
	for(int i=1;i<=n;i++)cout<<"("<<a<<","<<i<<")";
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<"("<<i<<","<<b<<")";
	cout<<endl;
	while(ta>=2&&tb>=2)ta--,tb--;
	while(ta<=n&&tb<=n){cout<<"("<<ta<<","<<tb<<")";ta++;tb++;}
	cout<<endl;
	while(a<=n-1&&b>=2)a++,b--;
	while(a>=1&&b<=n){cout<<"("<<a<<","<<b<<")";a--;b++;}
	return 0;
}