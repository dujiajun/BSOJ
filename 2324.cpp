#include<iostream>
using namespace std;
const int INF=0x7fffffff/2;
int t,a,n,f[105][105]={0},o2,n2,w,ans=INF;
int main()
{
	cin>>t>>a>>n;
	for(int i=0;i<=100;i++)
	for(int j=0;j<=100;j++)f[i][j]=INF;
	f[0][0]=0;
	for(int k=1;k<=n;k++)
	{
		cin>>o2>>n2>>w;
		for(int i=100;i>=o2;i--)
		for(int j=100;j>=n2;j--)
		f[i][j]=min(f[i][j],f[i-o2][j-n2]+w);
	}
	for(int i=t;i<=100;i++)
		for(int j=a;j<=100;j++)ans=min(ans,f[i][j]);
	cout<<ans;
	return 0;
} 
/*
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119
*/