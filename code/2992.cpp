#include<iostream>
#include<algorithm>
using namespace std;
struct point{int a,b;}a[100005];
int n,b[100005],c[100005],maxx=0;
inline bool cmp1(const point &p1,const point &p2){return p1.a<p2.a;}
inline int lowbit(int i){return i&(-i);}
void add(int x){for(int i=x;i<=n;i+=lowbit(i))c[i]++;}
int ask(int x)
{
	int tmp=0;
	for(int i=x;i>=1;i-=lowbit(i))tmp+=c[i];
	return tmp;
}
int bfind(int m,int k)
{
	int l=1,r=maxx,mid=0,tmp=0;
	while(l<r)
	{
		mid=(l+r)/2;
		tmp=ask(mid);
		if(tmp>=k)r=mid;
		else l=mid+1;
	}
	return r;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].b=i;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++)b[a[i].b]=i;
	for(int i=1;i<=n;i++)
	{
		add(b[i]);
		maxx=max(maxx,b[i]);
		if(i&1)printf("%d\n",a[bfind(i,(i+1)/2)].a);
	}
	return 0;
}