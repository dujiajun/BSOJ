#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,t=0,l[220000]={0},r[220000]={0},p[220000]={0},le=0,ri=0,v[220000]={0},w[220000]={0};
long long maxw=0,s,ans=0x7fffffffffffffffll,pn[220000]={0},pv[220000]={0};
long long check(int mid)
{
	long long sum=0;
	memset(pv,0,sizeof(pv));
	memset(pn,0,sizeof(pn));
	for(int i=1;i<=n;i++)
	{
		pn[i]=pn[i-1];
		pv[i]=pv[i-1];
		if(w[i]>=mid)
		{
			pn[i]++;
			pv[i]+=v[i];
		}
	}
	for(int i=1;i<=m;i++)sum+=(pv[r[i]]-pv[l[i]-1])*(pn[r[i]]-pn[l[i]-1]);
	return sum;
}
int main()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&v[i]);
		ri=max(ri,w[i]);
	}
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
	while(le<=ri)
	{
		int mid=(le+ri)/2;
		long long t=check(mid),va=abs(s-t);
		ans=min(ans,va);
		if(t<s)ri=mid-1;
		else le=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 3 15
1 5
2 5
3 5
4 5
5 5

1 5
2 4
3 3

10 10 1475400
23954 25180
18805 2701
17195 5663
7044 13659
8139 30927
19774 25516
7472 4572
5999 6166
1185 13621
10414 26521
2 10
4 7
5 8
1 6
2 7
1 3
2 7
3 4
1 6
1 10

*/