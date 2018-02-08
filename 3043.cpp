#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,x[105],w[105],v[105],c[105],q[105],bj,cnt;
bool vst[2005];
long long f[2005],ans=0,vv[105],ww[105];
inline long long fx(int aa,int bb,int xx){return (long long)aa*xx*xx-(long long)bb*xx;}
void readin()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		if(x[i]==1) scanf("%d%d",&w[i],&v[i]);q[++q[0]]=i;
		if(x[i]==2) scanf("%d%d%d",&w[i],&v[i],&c[i]);
		if(x[i]==3) scanf("%d%d",&w[i],&v[i]);
	}
}
void dp1()
{
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1)
		{
			for(int j=m;j>=1;j--)
			for(int k=1;k<=j;k++)f[j]=max(f[j],f[j-k]+fx(w[i],v[i],k));
		} 
		if(x[i]==2)
		{
			for(int j=1;j<=c[i];j++)
			for(int k=m;k>=v[i];k--)f[k]=max(f[k],f[k-v[i]]+w[i]);
		}
		if(x[i]==3)for(int j=v[i];j<=m;j++)f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
	ans=f[m];
}
int main()
{
	readin();
	dp1();
	cout<<ans<<endl;
	return 0;
}
/*
3 10
2 1 2 1
3 5 2
2 200 2 3

4 10
2 1 2 1
1 1 2
3 5 2
2 200 2 3
*/