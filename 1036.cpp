#include<iostream>
using namespace std; 
long long f[55]={0},n;
int main()
{   
	cin>>n;
	f[1]=2;f[2]=3;
	for(int i=3;i<=n;i++)f[i]=f[i-1]+f[i-2];
	cout<<f[n];
	return 0;
 }