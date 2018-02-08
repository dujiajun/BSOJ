#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct star{int x,y,pos;}a[100001];
int c[100005]={0},n,ans[100005]={0},maxy=-1;
bool cmp(star b,star d){return b.x<d.x||(b.x==d.x&&b.y>d.y);}
int lowbit(int i){return i&(-i);}
int modify(int x){for(int i=x;i<=maxy;i+=lowbit(i))c[i]++;}
int sum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].x++;a[i].y++;a[i].pos=i;
		maxy=max(a[i].y,maxy);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].y==a[i-1].y&&a[i].x==a[i-1].x)ans[a[i].pos]=ans[a[i-1].pos];
		else ans[a[i].pos]=sum(maxy)-sum(a[i].y-1);
		modify(a[i].y);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
}
int main()
{
	while(cin>>n)
	{
		if(n==0)break;
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		maxy=0;
		solve();
	}
	return 0;
}