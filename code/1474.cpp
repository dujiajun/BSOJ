#include<iostream>
using namespace std;
const int M=0xffff;
int v[400]={0},f[400][400]={0},g[400]={0},t[400],v0,g0,n,i,j,k;
int main()
{
	cin>>v0>>g0>>n;
	for(i=1;i<=n;i++)cin>>t[i]>>v[i]>>g[i];
	for(i=1;i<=n;i++)
		for(j=v0;j>=v[i];j--)
			for(k=g0;k>=g[i];k--)
				f[j][k]=max(f[j][k],f[j-v[i]][k-g[i]]+t[i]);
	cout<<f[v0][g0];
	return 0;
}