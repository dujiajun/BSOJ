#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
const int MOD=2012,N=35;
int A[N][N]={0},n,k,ans[N][N]={0},tmp[N][N],x[100],w[100],E[N][N]={0},t2[N][N];
void mcopy(int d[][N],const int e[][N])
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)d[i][j]=e[i][j];
}
void mplus(int d[][N],const int e[][N])
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)d[i][j]=(d[i][j]+e[i][j])%MOD;
}
void mcheng(int d[][N],const int e[][N])
{
	int ret[N][N]={0};
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)ret[i][j]=(ret[i][j]+d[i][k]*e[k][j]%MOD)%MOD;
	mcopy(d,ret);
}
void mi(int st[][N],int m)
{
	x[0]=0;
	mcopy(t2,st);
	while(m)
	{
		x[++x[0]]=m%2;
		m/=2;
	}
	for(int i=x[0]-1;i;i--)
	{
		mcheng(t2,t2);
		if(x[i])mcheng(t2,st);
	}
	mcopy(st,t2);
}
void solve()
{
	int t=k;
	w[0]=0;
	mcopy(ans,A);
	while(t)
	{
		w[++w[0]]=t%2;
		t/=2;
	}
	for(int i=w[0]-1,j=1;i;i--)
	{
		mcopy(tmp,A);
		mi(tmp,j);
		mplus(tmp,E);
		mcheng(ans,tmp);
		j<<=1;
		if(w[i])
		{
			j++;
			mcopy(tmp,A);
			mi(tmp,j);
			mplus(ans,tmp);
		}
	}
	mcopy(tmp,A);
	mi(tmp,9);
	mcheng(ans,tmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)cin>>A[i][j];
	for(int i=1;i<=n;i++)E[i][i]=1;
	solve();
	return 0;
}
/*
10 10000
1 2 3 4 5 6 7 8 9 10 
2 3 4 5 6 7 8 9 10 1 
3 4 5 6 7 8 9 10 1 2 
4 5 6 7 8 9 10 1 2 3 
5 6 7 8 9 10 1 2 3 4 
6 7 8 9 10 1 2 3 4 5 
7 8 9 10 1 2 3 4 5 6 
8 9 10 1 2 3 4 5 6 7 
9 10 1 2 3 4 5 6 7 8 
10 1 2 3 4 5 6 7 8 9 
*/