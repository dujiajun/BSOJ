#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[205]={0},b[205]={0},f[205][205]={0};
int main()
{
	int n,i,l,s,t;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];cin>>b[i];}
	for(l=1;l<n;l++)
	for(s=1;s<=n-l;s++)
	{
		t=s+l;
		f[s][t]=0xfffffff/2;
		for(i=s;i<t;i++)
		  f[s][t]=min(f[s][t],f[s][i]+f[i+1][t]+a[s]*b[i]*b[t]);
	}
	cout<<f[1][n];
	return 0;
}
