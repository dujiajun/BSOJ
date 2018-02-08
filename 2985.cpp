#include<iostream>
using namespace std;
int n,f[1005][1005]={0};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)f[i][1]=f[1][i]=1;
	for(int i=2;i<=n;i++)
	for(int j=2;j<=n;j++)f[i][j]=(f[i-1][j]+f[i][j-1])%100003;
	cout<<f[n][n]<<endl;
	return 0;
}