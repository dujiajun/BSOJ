#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{int x,y;}q[505];
struct edge{int p1,p2;double v;}w[250005]; 
int k,n,father[505]={0},t=1;
double ans=0;
bool cmp(edge e1,edge e2){return e1.v<e2.v;}
double dis(point p1,point p2){return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));}
void init()
{
	cin>>k>>n;
	for(int i=1;i<=n;i++)cin>>q[i].x>>q[i].y;
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	{
		w[t].p1=i;
		w[t].p2=j;
		w[t].v=dis(q[i],q[j]);
		t++;
	}
}
int getfather(int x)
{
	if(father[x]==x)return x;
	father[x]=getfather(father[x]);
	return father[x];
}
void solve()
{
	int b=0;
	sort(w+1,w+t+1,cmp);
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=t;i++)
	{
		int f1=getfather(w[i].p1),f2=getfather(w[i].p2);
		if(f1!=f2)
		{
			father[f2]=f1;
			b++;
			ans=w[i].v;
			if(b==n-k)break;
		}
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}