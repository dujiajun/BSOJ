#include<iostream>
#include<algorithm>
using namespace std;
struct point{int x,y;}a[15005];
int n,c[60005],maxx;
inline bool cmp(const point &p1,const point &p2){return p1.x<p2.x||p1.x==p2.x&&p1.y<p2.y;}
inline int lowbit(int i){return i&(-i);}
void add(int x){for(int i=x;i<=maxx;i+=lowbit(i))c[i]++;}
int ask(int x)
{
	int tmp=0;
	for(int i=x;i>=1;i-=lowbit(i))tmp+=c[i];
	return tmp;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].y++;a[i].x++;
		maxx=max(a[i].y,maxx);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		add(a[i].y);
		printf("%d\n",ask(a[i].y));
	}
	return 0;
}
/*
5
1 2
2 1
2 2
3 2
4 4
*/