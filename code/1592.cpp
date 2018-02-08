#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct point{double x,y;}a[60005]; 
int n;
bool cmp(point p1,point p2){return (p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y));}
double dis(point p1,point p2){return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);}
double solve(int l,int r)
{
	if(l+1==r)return dis(a[l],a[r]);
	if(l+2==r)return min(min(dis(a[l],a[l+1]),dis(a[l],a[r])),dis(a[l+1],a[r]));
	int mid=(l+r)/2;
	double t=min(solve(l,mid),solve(mid+1,r));
	for(int i=mid;i>=l;i--)
	for(int j=mid+1;j<=r;j++)
	{
		if((a[i].x-a[j].x)*(a[i].x-a[j].x)>=t)return t;
		if((a[i].y-a[j].y)*(a[i].y-a[j].y)>=t)continue;
		t=min(t,dis(a[i],a[j]));
	}
	return t;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	cout<<fixed<<setprecision(2)<<sqrt(solve(1,n));
	return 0;
}
/*
3
1 1
1 2
2 2
*/