#include<iostream>
#include<algorithm>
using namespace std;
struct tree{long long c,s;}t[100000];
struct cow{int x,v;}a[25005];
int n,maxx=0,minx=20500,L,R;
long long sum[25005],ans,res,now;
inline bool cmp(cow c1,cow c2){return c1.v<c2.v||c1.v==c2.v&&c1.x<c2.x;}
void Insert(int v,int l,int r,int p)
{
	t[v].s+=p;t[v].c++;
	if(l==r)return;
	int mid=(l+r)/2;
	if(mid>=p)Insert(2*v,l,mid,p);
	else Insert(2*v+1,mid+1,r,p);
}
long long Ask(int v,int l,int r)
{
	if(t[v].c==0)return 0;
	if(L<=l&&R>=r)return t[v].s-t[v].c*now;
	int mid=(l+r)/2;
	long long t=0;
	if(mid>=L)t+=Ask(2*v,l,mid);
	if(mid<R)t+=Ask(2*v+1,mid+1,r);
	return t;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].v,&a[i].x);
		minx=min(minx,a[i].x);
		maxx=max(maxx,a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		now=a[i].x;
		L=a[i].x,R=maxx;
		res+=a[i].v*Ask(1,minx,maxx);
		L=minx,R=a[i].x;
		res-=a[i].v*Ask(1,minx,maxx);
		Insert(1,minx,maxx,a[i].x);
	}
	cout<<res<<endl;
	return 0;
}
/*
4
3 1
2 5
2 6
4 3
*/