#include<iostream>
#include<cstdio>
using namespace std;
int a[1005][1005],h[1005][1005],l[1005][1005],r[1005][1005];
int m,n,c;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i][0]=0;h[i][0]=0;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&c);
			a[i][j]=c+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			if(c==0)h[i][j]=0;
			else h[i][j]=h[i-1][j]+1;
		}

		l[i][0]=0;
		for(int j=1;j<=m;j++)
    		if(h[i][j]==0)l[i][j]=0;
       		else l[i][j]=l[i][j-1]+1;
       		
       	r[i][m+1]=0;
		for(int j=m;j>=1;j--)
    		if(h[i][j]==0)r[i][j]=0;
			else r[i][j]=r[i][j+1]+1;
	}
	
	int ans=0,x1,x2,y1,y2,maxx;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(h[i][j]>0)
		{
			if(h[i][j]>1)
			{
				l[i][j]=min(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
			} 
			x2=i;y2=j+r[i][j]-1;
			x1=i-h[i][j]+1;y1=j-l[i][j]+1;
			maxx=a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
			ans=max(maxx,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
