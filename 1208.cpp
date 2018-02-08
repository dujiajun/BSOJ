#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int a,b,v;}a[100005];
int n,c[305],fa[305],t,k,ans=0,minn=1<<29,vst[305][305];
int getfa(int x)
{
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
bool cmp(edge e1,edge e2){return e1.v<e2.v;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[++t].a=0;a[t].b=i;a[t].v=c[i];
	}
	for(int i=1;i<=n;i++)
	for(int j=1,x;j<=n;j++)
	{
		cin>>x;
		if(!vst[i][j]&&!vst[j][i]){a[++t].a=i;a[t].b=j;a[t].v=x;vst[i][j]=vst[j][i]=1;}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=t;i++)
	{
		int f1=getfa(a[i].a),f2=getfa(a[i].b);
		if(f1!=f2)
		{
			ans+=a[i].v;
			fa[f1]=f2;
			k++;
			if(k==n)break;
		}
	}
	cout<<ans<<endl;
	return 0;
}