#include<iostream>
using namespace std;
int k,a1,a2,a3,bj=0;
bool check(int x)
{
	a1=x/100;
	a2=(x/10)%1000;
	a3=x%1000;
	return a1%k==0&&a2%k==0&&a3%k==0;
}
int main()
{
	cin>>k;
	for(int i=10000;i<=30000;i++)if(check(i)){cout<<i<<endl;bj++;}
	if(bj==0)cout<<"No"<<endl;
	return 0;
}