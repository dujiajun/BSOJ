#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{int a,b;}tmp[100005],a[100005],q[100005];
int n,m,p,t,minn=1<<29,f[100005][20];
inline bool cmp(node n1,node n2){return n1.a<n2.a||n1.a==n2.a&&n1.b<n2.b;} 
int bfind(int x)
{
	int l=1,r=n,mid;
	if(a[n].a<x)return -1;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid].a>=x)r=mid;
		else l=mid+1;
	}
	return r;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b);
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].a,&q[i].b);
	sort(a+1,a+n+1,cmp);
	tmp[++t]=a[1];
	for(int i=2;i<=n;i++)if(a[i].a!=a[i-1].a)tmp[++t]=a[i];
	for(int i=1;i<=t;i++)a[i]=tmp[i];
	n=t;t=0;
	minn=a[n].b;
	tmp[++t]=a[n];
	for(int i=n-1;i>=1;i--)
	if(a[i].b<minn)
	{
		minn=a[i].b;
		tmp[++t]=a[i];
	}
	for(int i=1;i<=t;i++)a[t-i+1]=tmp[i];
	n=t;t=0;
	for(int i=1;i<=n;i++)
	{
		while(p<=n&&a[p].a<a[i].b)p++;
		if(p>n)break;
		f[i][0]=p;
	}
	for(int j=1;j<=18;j++)
	for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1,x,ans;i<=m;i++)
	{
		x=bfind(q[i].a);
		if(x==-1||q[i].b<a[x].b)printf("0\n");
		else
		{
			ans=1;
			for(int j=18;j>=0;j--)
			if(f[x][j]&&a[f[x][j]].b<=q[i].b)
			{
				ans+=1<<j;
				x=f[x][j];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}