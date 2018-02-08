#include<iostream>
using namespace std;
int n,m,fa[50005],cnt,ans;
int getfa(int x)
{
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
void solve()
{
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,x,y,f1,f2;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		f1=getfa(x);f2=getfa(y);
		if(f1!=f2)fa[f1]=f2;
	}
	ans=0;
	for(int i=1;i<=n;i++)if(fa[i]==i)ans++;
	cout<<"Case "<<cnt<<": "<<ans<<endl;
}
int main()
{
	while(1)
	{
		cin>>n>>m;
		if(n==0&&m==0)break;
		cnt++;
		solve();
	}
	return 0;
}