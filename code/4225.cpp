#include<iostream>
#include<algorithm>
using namespace std;
struct course{int x,t;}a[1005];
int n,m,b,f[1005][1005][2],ans=1<<29;
inline bool cmp(const course &c1,const course &c2){return c1.x<c2.x;}
int main()
{
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].t);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)f[i][j][0]=f[i][j][1]=1<<29;
	f[1][n][0]=max(a[1].x,a[1].t);f[1][n][1]=max(a[n].x,a[n].t); 
	for(int i=1;i<=n;i++)
	for(int j=n;j>=i;j--)
	{
		if(i-1>=1)
		{
			f[i][j][0]=min(f[i][j][0],max(f[i-1][j][0]+a[i].x-a[i-1].x,a[i].t));
			f[i][j][1]=min(f[i][j][1],max(f[i-1][j][0]+a[j].x-a[i-1].x,a[j].t));
		}
		if(j+1<=n)
		{
			f[i][j][0]=min(f[i][j][0],max(f[i][j+1][1]+a[j+1].x-a[i].x,a[i].t));
			f[i][j][1]=min(f[i][j][1],max(f[i][j+1][1]+a[j+1].x-a[j].x,a[j].t));
		}
	}
	for(int i=1;i<=n;i++)ans=min(ans,min(f[i][i][0],f[i][i][1])+abs(a[i].x-b));
	cout<<ans<<endl;
	return 0;
}
/*
4 10 3
8 9
4 21
3 16
8 12
*/