#include<iostream>
using namespace std;
int n,m,fa[100005]={0},bin[100005]={0},maxx=1;
int getfa(int x)
{
	if(fa[x]==x)return fa[x];
	else return fa[x]=getfa(fa[x]);
}
int main()
{
	//freopen("rebell.in","r",stdin);
	//freopen("rebell.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){fa[i]=i;bin[i]=1;}
	for(int i=1,a,b,d;i<=m;i++)
	{
		scanf("%d",&d);
		if(d==1)
		{
			scanf("%d%d",&a,&b);
			if(getfa(a)!=getfa(b))
			{
				bin[fa[b]]+=bin[fa[a]];
				fa[fa[a]]=fa[b];
				maxx=max(maxx,bin[fa[b]]);
			}
		}
		else if(d==2)printf("%d\n",maxx);
	}
	return 0;
}
/*
2 3
2
1 1 2
2
*/