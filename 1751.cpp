#include<iostream>
#include<cstdio>
using namespace std;
int a[305][305]={0},b[305][305]={0};
int m,n,ans=0,c,l,maxx,h,sum;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&c);
		a[i][j]=c+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		if(c==0)b[i][j]=0;
		else b[i][j]=b[i][j-1]+1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(b[i][j]>0)
		{
			l=b[i][j];
			maxx=a[i][j]-a[i-1][j]-a[i][j-l]+a[i-1][j-l];
			h=i-1;
			while(h>=1&&b[h][j]>0)
			{
				l=min(l,b[h][j]);
				sum=a[i][j]-a[h-1][j]-a[i][j-l]+a[h-1][j-l];
				maxx=max(maxx,sum);
				h--;
			}
			ans=max(maxx,ans);
		}
	}
	cout<<ans;
	return 0;
}