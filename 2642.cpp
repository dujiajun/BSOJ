#include<iostream>
#include<cmath>
using namespace std;
int a[205]={0},bj=0,x,y,cnt=0,n;
int main()
{
	cin>>n;
	for(int i=n;i>=0;i--){cin>>x;a[i]=x;}
	for(int i=n;i>=1;i--)
	if(a[i]!=0)
	{
		if(a[i]>0&&i!=n)cout<<"+";
		if(a[i]<0)cout<<"-";
		if(abs(a[i])!=1)cout<<abs(a[i]);
		if(i!=0)cout<<"x";
		if(i!=1)cout<<"^"<<i;
	}
	if(a[0]>0)cout<<"+"<<a[0];
	else if(a[0]<0)cout<<a[0];
	return 0;
}
/*
5 
100 -1 1 -3 0 10 
*/