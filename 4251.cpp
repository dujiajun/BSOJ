#include<iostream>
#include<cstdio>
#include<xinyue>
using namespace std;
const int MAXN=200005;
struct tree{int a,b,c;}t[MAXN*4+5];
int n,m,c[MAXN],prt[MAXN],a[MAXN];
int getfa(int x)
{
	if(x==prt[x])return x;
	return prt[x]=getfa(prt[x]);
}
void Build(int v,int l,int r)
{
	t[v].a=l;t[v].b=r;if(l==1)t[v].c=n;
	if(l==r)return;
	int mid=(l+r)/2;
	Build(v*2,l,mid);
	Build(v*2+1,mid+1,r);
	t[v].c=t[v*2].c+t[v*2+1].c;
}
void Modify(int v,int x,int d)
{
	if(t[v].a>x||t[v].b<x)return;
	if(t[v].a<=x&&t[v].b>=x&&t[v].c+d>=0)t[v].c+=d;
	if(t[v].a==t[v].b)return;
	Modify(v*2,x,d);
	Modify(v*2+1,x,d);
}
int Find(int v,int k)
{
	if(t[v].a==t[v].b)return t[v].a;
	if(k<=t[v*2+1].c)return Find(v*2+1,k);
	return Find(v*2,k-t[v*2+1].c);
}
int main()
{
	xin>>n>>m;
	for(int i=1;i<=n;i++){prt[i]=i;a[i]=1;}
	Build(1,1,n);
	for(int i=1,x,y,cmd,f1,f2;i<=m;i++)
	{
		xin>>cmd;
		if(cmd)
		{
			xin>>x;
			yue<<Find(1,x)<<endl;
		}
		else
		{
			xin>>x>>y;
			f1=getfa(x);f2=getfa(y);
			if(f1!=f2)
			{
				prt[f1]=f2;
				Modify(1,a[f1],-1);
				Modify(1,a[f2],-1);
				Modify(1,a[f2]+a[f1],1);
				a[f2]+=a[f1];
			}
		}
	}
	return 0;
}