#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int x,y,t;}w[100005];
int n,m,fa[1005]={0},ans=0;
bool cmp(edge e1,edge e2){return e1.t<e2.t;}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i].x>>w[i].y>>w[i].t;
	for(int i=1;i<=n;i++)fa[i]=i;
}
int getfa(int x)
{
	if(fa[x]==x)return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void solve()
{
	int f1,f2,b=0;
	sort(w+1,w+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		f1=getfa(w[i].x),f2=getfa(w[i].y);
		if(f1!=f2)
		{
			fa[f1]=f2;
			ans=w[i].t;
			b++;
		}
	}
	if(b==n-1)cout<<ans<<endl;
	else cout<<-1<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}
/*
4 4
1 2 6
1 3 4
1 4 5
4 2 3
*/