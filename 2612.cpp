#include<iostream>
using namespace std;
const int MAXN=1000005;
int n=0,a[1000005],t,e[MAXN];
long long f[MAXN];
void get_phi()
{
	for(int i=1;i<=n;i++)e[i]=i;
   	for(int i=2;i<=n;i+=2)e[i]=e[i]/2;
   	for(int i=3;i<=n;i+=2)
    if(e[i]==i)for(int j=i;j<=n;j+=i)e[j]=e[j]-e[j]/i;
}
void calc()
{
	for(int i=1;i<=n;i++)
    for(int j=2;j<=n/i;j++)f[i*j]+=e[j]*i;
   	for(int i=2;i<=n;i++)f[i]+=f[i-1];
}
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&a[i]);
		n=max(a[i],n);
	}
	get_phi();
	calc();
	for(int i=1;i<=t;i++)printf("%lld\n",f[a[i]]);
	return 0;
}