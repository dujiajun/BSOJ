#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r;
long long a[40005],b[40005],f[40005],g[40005],va,vb,ans;
struct edge{int a,b;}e[100005];
inline bool cmp(edge e1,edge e2){return e1.a<e2.a||e1.a==e2.a&&e1.b<e2.b;}
int main()
{
	cin>>n>>m>>r; 
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);f[i]=a[i];}
	for(int i=1;i<=m;i++){scanf("%d",&b[i]);g[i]=b[i];}
	for(int i=1;i<=r;i++)scanf("%d%d",&e[i].a,&e[i].b);
	sort(e+1,e+r+1,cmp);
	for(int i=r;i>=1;i--)
	{
		va=a[e[i].a]+g[e[i].b];
		vb=b[e[i].b]+f[e[i].a];
		f[e[i].a]=max(f[e[i].a],va);
		g[e[i].b]=max(g[e[i].b],vb);
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	for(int i=1;i<=m;i++)ans=max(ans,g[i]);
	cout<<ans<<endl;
	return 0;
}