#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int a,b,v;}a[100005];
int n,m,fa[10005],ans;
bool cmp(const edge &x,const edge &y){return x.v<y.v;}
int getfa(int x)
{
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].v);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int f1=getfa(a[i].a),f2=getfa(a[i].b);
		if(f1!=f2)
		{
			fa[f1]=f2;
			ans+=a[i].v;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 8
1 2 2
1 3 12
1 4 10 
2 3 8
2 5 9
3 4 6
3 5 3
4 5 7
*/