#include<iostream>
using namespace std;
int n;
long long f[1005]={0};
int main()
{
	cin>>n;
	f[0]=1;f[1]=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++)f[i]+=f[j]*f[i-j-1];
	cout<<f[n]<<endl;
	return 0;
}