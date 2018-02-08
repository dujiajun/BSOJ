#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000005;
int n,m,a[MAXN],s[MAXN],sum[MAXN],d[MAXN],st[MAXN],ed[MAXN];
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=m;i++)scanf("%d%d%d",&d[i],&st[i],&ed[i]);
}
bool check(int x)
{
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=x;i++)
	{
		sum[st[i]]-=d[i];
		sum[ed[i]+1]+=d[i];
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{
		now+=sum[i]+s[i];
		if(now<0)return 0;
	}
	return 1;	
}
void erfen()
{
	int l=1,r=m+1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	if(r==m+1)cout<<0<<endl;
	else cout<<-1<<endl<<r<<endl;
}
int main()
{
	init();
	erfen();
	return 0;
} 