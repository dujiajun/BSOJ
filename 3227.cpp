#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct point{double x,y;}a[100005]; 
int n,b[100005]={0},tot=0;
inline bool cmp1(point p1,point p2){return (p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y));}
inline double dis(point p1,point p2){return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);}
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
inline double cross(point p0,point p1,point p2){return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);}
inline bool cmp2(point p1,point p2)
{
    double t=cross(a[1],p1,p2);
    if(t>0)return 1;
    else if(t==0)return dis(a[1],p1)<dis(a[1],p2);
    else return 0;      
}
double rotating_calipers(int m)
{ 
	int q=1;
	double ans=0;
	a[b[n+1]]=a[b[1]];
	for(int p=1;p<=m;p++)
	{
		while(cross(a[b[p+1]],a[b[q+1]],a[b[p]])>cross(a[b[p+1]],a[b[q]],a[b[p]]))q=(q+1)%m;
		ans=max(ans,max(dis(a[b[p]],a[b[q]]),dis(a[b[p+1]],a[b[q+1]])));
	}
	return ans;
}
void solve2()
{
	int minn,minx=0x7fffffff/2,miny=0x7fffffff/2; 
   	for(int i=1;i<=n;i++)if(miny>a[i].y||miny==a[i].y&&minx>a[i].x){minn=i;miny=a[i].y;minx=a[i].x;}
   	swap(a[1],a[minn]);  
   	sort(a+2,a+n+1,cmp2);  
   	b[1]=1;b[2]=2;tot=2;
   	for(int i=3;i<=n;i++)
   	{
   		while(cross(a[b[tot]],a[b[tot-1]],a[i])>=0&&tot>1)tot--;        
   		b[++tot]=i;        
   	}
   	double maxx=0; 
    cout<<fixed<<setprecision(2)<<sqrt(rotating_calipers(tot))<<endl;    
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp1);
	cout<<fixed<<setprecision(2)<<sqrt(solve(1,n))<<" ";
	solve2();
	return 0;
}