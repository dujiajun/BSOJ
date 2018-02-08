#include<iostream>
using namespace std;
int w[505][505]={0},v[505][505]={0},c[505]={0};
void print(int i,int j)
{
	if(i==0)return;
	print(i-1,j-v[i][j]*c[i]);
	cout<<v[i][j]<<endl;
}
int main()
{
	int f[505]={0},i,j,n,m,k,p[505]={0},maxx=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{	cin>>c[i]>>p[i];
		for(j=1;j<=p[i];j++)cin>>w[i][j];}
	for(i=1;i<=n;i++)
		for(j=m;j>=c[i];j--)
			for(k=1;k<=p[i];k++)
				if(j-k*c[i]>=0)
				if(f[j]<f[j-c[i]*k]+w[i][k]){f[j]=f[j-c[i]*k]+w[i][k];v[i][j]=k;}
	for(i=0;i<=m;i++)if(f[i]>f[maxx])maxx=i;
	cout<<f[maxx]<<endl;
	print(n,maxx);
	return 0;
}