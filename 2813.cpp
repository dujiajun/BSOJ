#include<iostream>
#include<algorithm>
using namespace std;
int x1,x2,y1,y2,n,r1=0,r2=0,ans=0x7fffffff/2;
struct dx{int x,y;}p[100005]={0};
bool cmp(dx p1,dx p2){return p1.x<p2.x;}
int dis(int x1,int y1,int x2,int y2)
{return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);}
int main()
{
 	cin>>x1>>y1>>x2>>y2;
 	cin>>n;
 	for(int i=1,x,y;i<=n;i++)
 	{
 		cin>>x>>y;
 		p[i].x=dis(x,y,x1,y1);
 		p[i].y=dis(x,y,x2,y2);
 	}
	sort(p+1,p+n+1,cmp);
 	for(int i=n;i>=1;i--)
 	{
 		if(ans>p[i].x+r2)ans=p[i].x+r2;
 		if(r2<p[i].y)r2=p[i].y;
 	}
 	cout<<ans;
	return 0;
}
/*
0 0 6 0
5
-4 -2
-2 3
4 0
6 -2
9 1

0 0 10 0
2
-3 3
10 0
*/