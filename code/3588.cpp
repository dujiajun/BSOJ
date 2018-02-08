#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[2000];
int n,m,cnt,h[1000],p[1000][20],prt[1000],vst[1000],d[1000],sum[1000];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x,int dp)
{
	vst[x]=1;d[x]=dp;
	for(int i=h[x];i;i=a[i].next)
	if(!vst[a[i].to])dfs(a[i].to,dp+1);
}
void ST()
{
	memset(p,-1,sizeof(p));
	int t=log2(n);
	for(int i=1;i<=n;i++)p[i][0]=prt[i];
	for(int j=1;j<=t;j++)
	for(int i=1;i<=n;i++)if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
void LCA(int a,int b)
{
	if(d[a]<d[b])swap(a,b);
	int t=log2(d[a]);
	for(int i=t;i>=0;i--)if(d[a]-(1<<i)>=d[b])a=p[a][i];
	if(a==b){sum[a]++;return;}
	for(int i=t;i>=0;i--)
	if(p[a][i]!=-1&&p[a][i]!=p[b][i]){a=p[a][i];b=p[b][i];}
	if(p[a][0]!=-1)sum[p[a][0]]++;
}
void solve()
{
	char ch;
	for(int i=1,x,y,z;i<=n;i++)
	{
		cin>>x>>ch>>ch>>y>>ch;
		for(int j=1;j<=y;j++)
		{
			cin>>z;
			add(x,z);add(z,x);prt[z]=x;
		}
	}
	for(int i=1;i<=n;i++)if(prt[i]==0){dfs(i,1);break;}
	ST();
	cin>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>ch>>x>>ch>>y>>ch;
		LCA(x,y);
	}
	for(int i=1;i<=n;i++)
	if(sum[i])cout<<i<<":"<<sum[i]<<endl;
}
int main()
{
	while(cin>>n)
	{
		memset(vst,0,sizeof(vst));
		memset(sum,0,sizeof(sum));
		memset(h,0,sizeof(h));
		memset(prt,0,sizeof(prt));
		memset(p,-1,sizeof(p));
		memset(d,0,sizeof(d));
		cnt=0;
		solve();
	}
	return 0;
}
/*
5
5:(3) 1 4 2
1:(0)
4:(0)
2:(1) 3
3:(0)
6
(1,5)
(1,4)
(4,2)
(2,3)
(1,3)
(4,3)
*/