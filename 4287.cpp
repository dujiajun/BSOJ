#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,nx[50],ny[50],ans,a[150][150];
long long tmp,maxx,nk[50];
int main()
{
	cin>>d>>n;
	for(int i=1;i<=n;i++)cin>>nx[i]>>ny[i]>>nk[i];
	for(int i=0;i<=128;i++)
	for(int j=0;j<=128;j++)
	{
		tmp=0;
		for(int k=1;k<=n;k++)if(nx[k]>=i-d&&nx[k]<=i+d&&ny[k]>=j-d&&ny[k]<=j+d)tmp+=nk[k];
		if(tmp>maxx)maxx=tmp;
	}
	for(int i=0;i<=128;i++)
	for(int j=0;j<=128;j++)
	{
		tmp=0;
		for(int k=1;k<=n;k++)if(nx[k]>=i-d&&nx[k]<=i+d&&ny[k]>=j-d&&ny[k]<=j+d)tmp+=nk[k];
		if(tmp==maxx)ans++;
	}
	cout<<ans<<" "<<maxx<<endl;
	return 0;
}
/*
1 
2 
4 4 10 
6 6 20 
*/
