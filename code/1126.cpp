#include<iostream>
using namespace std;
struct edge{int to,next;}a[8005];
int n,p,r,v[3005]={0},h[3005]={0},cnt=0,tot=0,scc=0,bel[3005]={0},minn[3005]={0},in[3005],num[3005]={0},
	dfn[3005]={0},low[3005]={0},sign=0,stack[3005]={0},instack[3005]={0},c[3005]={0};
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>n>>p;
	for(int i=1,x,y;i<=p;i++){cin>>x>>y;v[x]=y;}
	cin>>r;
	for(int i=1,x,y;i<=r;i++){cin>>x>>y;add(x,y);}
	for(int i=1;i<=n;i++){c[i]=1<<29;minn[i]=1<<29;}
}
void tarjan(int u)
{
	dfn[u]=low[u]=++sign;
	stack[++tot]=u;instack[u]=1;
	for(int i=h[u];i;i=a[i].next)
	{
		int to=a[i].to;
		if(!dfn[to])
		{
			tarjan(to);
			low[u]=min(low[u],low[to]);
		}
		else if(instack[to])low[u]=min(low[u],dfn[to]);
	}
	int t;
	if(dfn[u]==low[u])
	{
		scc++;
		do
		{
			t=stack[tot--];
			instack[t]=0;
			bel[t]=scc;
			if(t<=minn[scc])minn[scc]=t;
			if(v[scc]<=c[scc]&&v[t])c[scc]=v[t];
			//num[scc]+=v[scc];
		}while(t!=u);
	}
}
void solve()
{
	int bj,ans=0,jj=1<<29;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)
	for(int j=h[i];j;j=a[j].next)
	{
		int to=a[j].to;
		if(bel[i]!=bel[to])in[bel[to]]++;
	}
	for(int i=1;i<=scc;i++)
	{
		if(in[i]==0)
		{
			bj=0;
			for(int j=1;j<=n;j++)
				if(bel[j]==i&&v[j]){bj=1;break;}
			if(bj==1)ans+=c[i];
			if(bj==0){jj=min(jj,minn[i]);break;}
		}
	}
	if(bj==1)cout<<"YES"<<endl<<ans<<endl;
	else cout<<"NO"<<endl<<jj<<endl;
} 
int main()
{
	init();
	solve();
	return 0;
} 
/*
3	
2	
1 10
2 100
2
1 3
2 3
*/