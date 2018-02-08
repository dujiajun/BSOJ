#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct point{int x,y;}a[1000001];
long long n,m,t,k,c[1000001]={0},ans=0;
bool cmp(point x,point y){if(x.x==y.x)return x.y<y.y;return x.x<y.x;}
int lowbit(int i){return i&(-i);}
int add(int x){for(int i=x;i<=m;i+=lowbit(i))c[i]++;}
int sum(int x)
{
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i))sum+=c[i];
	return sum;
}
void solve(int q)
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+k+1,cmp);
	for(int i=k;i>0;i--)
	{
		ans+=sum(a[i].y-1);
		add(a[i].y);
	}
	printf("Test case %d: %lld\n",q,ans);
}
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		solve(i);
		memset(c,0,sizeof(c));ans=0;
	}
	return 0;
}