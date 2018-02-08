#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct point{double x,y;}a[30001];
int n,b[30001],tot;
double s,l;
double cross(point p0,point p1,point p2){return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);}
double dis(point p1,point p2){return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));}
bool cmp(point p1,point p2)
{
    double t=cross(a[1],p1,p2);
    if(t>0)return 1;
    else if(t==0)return dis(a[1],p1)<dis(a[1],p2);
    else return 0;      
}
void solve()
{
	int minn,minx=0x7fffffff,miny=0x7fffffff; 
   	for(int i=1;i<=n;i++)
   	{
   		cin>>a[i].x>>a[i].y;
   		if(miny>a[i].y||miny==a[i].y&&minx>a[i].x){minn=i;miny=a[i].y;minx=a[i].x;}
   	}   
   	swap(a[1],a[minn]);  
   	sort(a+2,a+n+1,cmp);  
   	b[1]=1;b[2]=2;tot=2;
   	for(int i=3;i<=n;i++)
   	{
   		while(cross(a[b[tot]],a[b[tot-1]],a[i])>=0&&tot>1)tot--;        
   		b[++tot]=i;        
   	}
   	double maxx=0; 
    for(int i=1;i<=tot;i++)
    for(int j=i+1;j<=tot;j++)maxx=max(maxx,dis(a[b[i]],a[b[j]]));
     cout<<fixed<<setprecision(2)<<maxx<<endl;    
}
int main()
{
    while(cin>>n)solve();
    return 0;
}