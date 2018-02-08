#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int to,next;}a[60005];
int n,si,cnt,h[60005],vst[60005],f[60005],res[60005],ans=1<<29;
inline void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
inline bool cmp(int x,int y){return x>y;}
int dp(int b,int fa)
{
	if(vst[b])return f[b];
	vst[b]=1;
	int x=a[b].to,son[6005]={0};
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)son[++son[0]]=dp(i,x);
	sort(son+1,son+son[0]+1,cmp);
	for(int i=1;i<=son[0];i++)f[b]=max(f[b],son[i]+i);
	return f[b]; 
}
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>si;
		add(i,si);
		add(si,i);
	}
	for(int i=1;i<=n;i++)add(n+1,i);
	for(int i=h[n+1],tmp;i;i=a[i].next)
	{
		tmp=dp(i,n+1)+1;
		if(tmp==ans)res[++res[0]]=a[i].to;
		if(tmp<ans){ans=tmp;res[0]=1;res[1]=a[i].to;};
	}
	cout<<ans<<endl;
	for(int i=res[0];i>=1;i--)cout<<res[i]<<" ";
	return 0;
} 
/*
8
1
1
3
4
4
4
3
*/