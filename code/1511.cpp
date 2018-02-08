#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[205]={0},b[205]={0},f[205][205]={0};
int main()
{
	int ans=0,n,i,l,s,t;
	cin>>n;
	for(i=1;i<=n;i++){cin>>a[i];a[i+n]=a[i];}
	for(i=1;i<=2*n-1;i++)b[i]=a[i+1];
	b[2*n]=a[i];
	for(l=2;l<=n;l++)
	for(s=1;s<=2*n-l;s++)
	{
		t=s+l-1;
		f[s][t]=0;
		for(i=s;i<t;i++)
		  f[s][t]=max(f[s][t],f[s][i]+f[i+1][t]+a[s]*b[i]*b[t]);
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i][i+n-1]);
	cout<<ans;
	return 0;
}
