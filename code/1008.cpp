#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int main()
{
	int a[7],b[7],i;
	for(i=0;i<7;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=0;i<7;i++)
		if(a[i]+b[i]>8)break;
	cout<<i+1;
	return 0;
}
