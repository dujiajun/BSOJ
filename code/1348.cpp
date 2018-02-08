#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[2505][2505],f[2505][2505]={0};
int n,m,ans=0,maxx=0,s,l,r;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&a[i][j]);
		f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		if(a[i][j]==1)maxx=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j]!=0)
		{
			s=1;l=1;r=1;
			while(a[i+s][j+l]==1)
			{
				r++;
				if(f[i+s][j+l]+f[i-1][j-1]-f[i-1][j+l]-f[i+s][j-1]==r)
				maxx=max(maxx,r);
				else break;
				s++;l++;
			}
			s=1;l=1;r=1;
			while(a[i+r][j-s]==1)
			{
				r++;
				if(f[i+l][j]-f[i+s][j-s-1]-f[i-1][j]+f[i-1][j-s-1]==r)
				maxx=max(maxx,r);
				else break;
				s++;l++;
			}
		}
	}
	cout<<maxx;
	return 0;
}