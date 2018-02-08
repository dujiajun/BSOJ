#include<iostream>
#include<algorithm>
using namespace std;
struct star{int x,y;}a[100001];
int c[100005]={0},n,m,ans[100005]={0};
bool cmp(star b,star d){return b.x<d.x||(b.x==d.x&&b.y<d.y);}
int lowbit(int i){return i&(-i);}
int modify(int x){for(int i=x;i<=n;i+=lowbit(i))c[i]++;}
int sum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){scanf("%d%d",&a[i].x,&a[i].y);a[i].y++;}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ans[sum(a[i].y)]++;
		modify(a[i].y);
	}
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}