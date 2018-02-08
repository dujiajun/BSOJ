#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
struct edge{int to,next;}a[1000005],b[1000005];
int n,cnt,h[2005],h2[2005],cnt2,ans=0,cou=0;
int low[2005],dfn[2005],sign=0,stack[2005],scc=0,tot=0,bl[2005],num[2005],in[2005],q[2005];
bool map[2005][2005],vst[2005],instack[2005];
bitset<2005>f[2005];
inline void adda(const int &x,const int &y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
inline void addb(const int &x,const int &y)
{
	b[++cnt2].to=y;
	b[cnt2].next=h2[x];
	h2[x]=cnt2;
}
inline char get_char()
{
	char c;
	while(1)
	{
		c=getchar();
		if(c=='0'||c=='1')return c;
	}
} 
void tarjan(int u)
{
	low[u]=dfn[u]=++sign;
	stack[++tot]=u;instack[u]=1;
	for(int i=h[u];i;i=a[i].next)
	{
		int v=a[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v])low[u]=min(low[u],dfn[v]);
	}
	int t;
	if(low[u]==dfn[u])
	{
		scc++;
		do
		{
			t=stack[tot--];
			bl[t]=scc;
			instack[t]=0;
			num[scc]++;
		}while(t!=u);
		
	}
}
void init()
{
	cin>>n;char ch;
	for(int i=1,j;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		ch=get_char();
		if(ch=='1')adda(i,j);
	}
}
void buildnew()
{
	for(int i=1,j,b1,b2;i<=n;i++)
	{
		b1=bl[i];
		for(j=h[i];j;j=a[j].next)
		{
			b2=bl[a[j].to];
			if(!map[b1][b2]&&b1!=b2)
			{
				map[b1][b2]=1;
				addb(b1,b2);
				in[b2]++; 
			}
		}
	}
}
void topsort()
{
	cou=0;int x;
	for(int i=1;i<=n;i++)f[bl[i]][i]=1;
	for(int i=1;i<=scc;i++)if(in[i]==0)q[++q[0]]=i;
	while(cou<q[0])
	{
		x=q[++cou];
		ans+=num[x]*f[x].count();
		for(int i=h2[x];i;i=b[i].next)
		{
			in[b[i].to]--;
			f[b[i].to]|=f[x];
			if(in[b[i].to]==0)q[++q[0]]=b[i].to;
		}
	}
}
int main()
{
	init();
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	buildnew();
	topsort();
	cout<<ans<<endl;
	return 0;
}