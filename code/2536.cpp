#include<iostream>
using namespace std;
int cnt,h[105],n,m,ans,f[105][105],dis[105],gap[105],a[1005],b[1005];
int sap(int x,int fl)
{
	if(x==n+1)return fl;
	int tmp=fl,dt;
	for(int i=0;i<=n+1;i++)
	if(f[x][i]>0&&dis[x]==dis[i]+1)
	{
		dt=sap(i,min(tmp,f[x][i]));
		tmp-=dt;
		f[x][i]-=dt;
		f[i][x]+=dt;
		if(dis[0]==n+2||tmp==0)return fl-tmp;
	}
	if(--gap[dis[x]]==0)dis[0]=n+2;
	else gap[++dis[x]]++;
	return fl-tmp;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1,k,x;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x;
			if(b[x]==0){f[0][i]+=a[x];b[x]=i;}
			else {f[b[x]][i]=1<<29;b[x]=i;}
		}
		cin>>x;
		f[i][n+1]=x;
	}
	gap[0]=n+2;
	while(dis[0]<n+2)ans+=sap(0,1<<29);
	cout<<ans<<endl;
	return 0;
}
/*
3 3
3 1 10
2 1 2 2
2 1 3 3
1 2 6
*/