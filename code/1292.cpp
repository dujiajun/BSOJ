#include<iostream>
using namespace std;
int a[30]={0},n,bj=0;char c1,c2,c3;
int main()
{
	cin>>n;a[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c1>>c2>>c3;
		a[c1-'a']=a[c3-'a'];
	}
	for(int i=0;i<=25;i++)if(a[i]){cout<<char(i+'a')<<" ";bj=1;}
	if(!bj)cout<<"none";
	return 0;
}