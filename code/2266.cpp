#include<iostream>
using namespace std;
int n,f[1000010]={1,1,2,5,0};
int main()
{
	cin>>n;
	f[1]=1;f[2]=2;f[3]=5;
	for(int i=4;i<=n;i++)f[i]=(2*f[i-1]+f[i-3])%10000;
	cout<<f[n]<<endl;
	return 0;
}