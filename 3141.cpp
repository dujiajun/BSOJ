#include<iostream>
#include<cstring>
using namespace std;
int n,m,c[210][210]={0},x[10005]={0},y[10005]={0},v[10005]={-1};
bool bomb[210][210]={0};
long long f[210][210]={0},k;
void dp()
{
	memset(bomb,0,sizeof(bomb));
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=0;i<m+n-1;i++)
	for(int j=0;j<=i;j++)
	{
		if(v[i+1]!=1)
		{
			f[i+1][j+1]+=f[i][j];
			if(f[i+1][j+1]<0||bomb[i][j])bomb[i+1][j+1]=1;
		}
		if(v[i+1]!=0&&j>0)
		{
			f[i+1][j-1]+=f[i][j];
			if(f[i+1][j-1]<0||bomb[i][j])bomb[i+1][j-1]=1;
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	memset(v,-1,sizeof(v));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>c[i][j];
		x[c[i][j]]=i;
		y[c[i][j]]=j;
	}
	for(int i=1;i<=n*m;i++)
	if(v[x[i]+y[i]-1]==-1)
	{
		v[x[i]+y[i]-1]=0;
		dp();
		if(f[n+m-1][0]>=k||bomb[n+m-1][0])continue;
		v[x[i]+y[i]-1]=1;
		k-=f[n+m-1][0];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		if(v[i+j-1]==0)cout<<"(";
		else cout<<")";
		cout<<endl;
	}
	return 0;
}