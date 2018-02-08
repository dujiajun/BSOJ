#include<iostream>
using namespace std;
int a,b,sum,tmp;
int power(int x,int y)
{
	int p=1;
	while(y)
	{
		if(y%2)p=x*p%1000;
		x=x*x%1000;
		y/=2;
	}
	return p;
}
int main()
{
	while(1)
	{
		cin>>a>>b;
		if(a==0&&b==0)break;
		cout<<power(a,b)<<endl;
	}
	return 0;
}