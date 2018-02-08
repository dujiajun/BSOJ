#include<iostream>
using namespace std;
int n,v,m[2005],w[2005]={0},s[2005]={0},f[505]={0},t=0;
int main()
{
 	cin>>n>>v;
 	for(int i=1;i<=n;i++)cin>>m[i]>>w[i]>>s[i];
 	for(int i=1;i<=n;i++)
 	for(int j=1;j<=m[i];j++)
	for(int k=v;k>=j*w[i];k--)f[k]=max(f[k-w[i]]+s[i],f[k]);
 	cout<<f[v];
	return 0;
}
/*
2 10 
3 4 3
2 2 5
*/
