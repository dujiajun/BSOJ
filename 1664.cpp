#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct edge{int a,b;double v;}e[200005];
double s,ans=0,z;
int n,m=1,fa[200005]={0},x,y;
int getfa(int x)
{
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
inline bool cmp(edge e1,edge e2){return e1.v<e2.v;}
bool check()
{
	for(int i=2;i<=n;i++)if(fa[i]!=fa[1])return 0;
	return 1;
}
int main()
{
	cin>>s>>n;
	while(cin>>x>>y>>z)
	{
		e[m].a=x;
		e[m].b=y;
		e[m].v=z;
		m++;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int f1,f2;
	for(int i=1;i<=m;i++)
	{
		f1=getfa(e[i].a);f2=getfa(e[i].b);
		if(f1!=f2)
		{
			fa[f1]=f2;
			ans+=e[i].v;
		}
	}
	if(!check())cout<<"Impossible"<<endl;
	else cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
/*
100.0
4
1 2 2.0
1 3 4.2
1 4 6.7
3 4 4.0
2 4 10.0
*/