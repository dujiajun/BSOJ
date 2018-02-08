#include<iostream>
#include<cstring> 
using namespace std;
struct edge{int to,next;}a[200005];
int n,cnt=0,h[100005]={0},f[100005][2]={0},v[100005]={0},maxx=0;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
int Find(int x,int t,int fr)
{
	if(f[x][t])return f[x][t];
	if(x==0)return 0;
	int sum=0;
	if(t==1)
	{
		sum=v[x];
		for(int i=h[x];i;i=a[i].next)
		{
			if(a[i].to==fr)continue;
			sum+=Find(a[i].to,0,x);
		}
		f[x][t]=sum;
	}
	else
	{
		for(int i=h[x];i;i=a[i].next)
		{
			if(a[i].to==fr)continue;
			sum+=max(Find(a[i].to,0,x),Find(a[i].to,1,x));
		}
		f[x][t]=sum;
	}
	return f[x][t];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	maxx=max(maxx,Find(1,0,0));
	memset(f,0,sizeof(f));
	maxx=max(maxx,Find(1,1,0));
	cout<<maxx<<endl;
	return 0;
}