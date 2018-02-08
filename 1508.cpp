#include<iostream>
using namespace std;
int f[30005]={0},v[30],w[30],n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>v[i]>>w[i];
	for(int j=1;j<=m;j++)
	for(int i=n;i>=v[j];i--)
		f[i]=max(f[i-v[j]]+v[j]*w[j],f[i]);
	cout<<f[n]<<endl;
}
/*
1000 5
800 2
400 5
300 5
400 3
200 2
*/