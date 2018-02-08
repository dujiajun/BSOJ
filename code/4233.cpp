#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<long long,int> pii;
priority_queue< pii >hx,hy;
int n,m,k,p,h[1005],l[1005];
long long ans=-9999999999999999ll,hmax[1000005],lmax[1000005];
int main()
{
	cin>>n>>m>>k>>p;
	for(int i=1,x;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&x);
		h[i]+=x;l[j]+=x;
	}
	while(!hx.empty())hx.pop();	
	while(!hy.empty())hy.pop();
	for(int i=1;i<=n;i++)hx.push(make_pair(h[i],i));
	for(int i=1;i<=k;i++)
	{
		pii u=hx.top();
		hx.pop();
		hmax[i]=hmax[i-1]+u.first;
		hx.push(make_pair(u.first-m*p,u.second));
	}
	for(int i=1;i<=m;i++)hy.push(make_pair(l[i],i));
	for(int i=1;i<=k;i++)
	{
		pii u=hy.top();
		hy.pop();
		lmax[i]=lmax[i-1]+u.first;
		hy.push(make_pair(u.first-n*p,u.second));
	}
	for(int i=0;i<=k;i++)ans=max(ans,hmax[i]+lmax[k-i]-i*1ll*(k-i)*p);
	cout<<ans<<endl;
	return 0;
}