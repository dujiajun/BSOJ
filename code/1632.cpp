#include<iostream>
#include<algorithm>
using namespace std;
struct pt{int x,y,v;}p[105];
int t=0,n,sum=0;
bool cmpx(pt p1,pt p2){return p1.x<p2.x;}
bool cmpy(pt p1,pt p2){return p1.y<p2.y;}
int d(pt p1,pt p2){return abs(p1.x-p2.x)+abs(p1.y-p2.y);}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y>>p[i].v;
		sum+=p[i].v;
	}
	sort(p+1,p+n+1,cmpx);
	for(int i=1;i<=n;i++)
	{
		t+=p[i].v;
		if(t>=sum/2){cout<<p[i].x<<" ";t=0;break;}
	}
	sort(p+1,p+n+1,cmpy);
	for(int i=1;i<=n;i++)
	{
		t+=p[i].v;
		if(t>=sum/2){cout<<p[i].y<<" ";t=0;break;}
	}
	return 0;
}