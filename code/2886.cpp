#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x7ff;
int n,map[305][305],ans,minn=INF,k;
void floyd()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
}
void init()
{
	int x,y,z;
	cin>>n;
	for(int i=0;i<305;i++)
	for(int j=0;j<305;j++)if(i==j)map[i][j]=0;else map[i][j]=INF;
	for(int i=2;i<=n;i++)
	{
		cin>>x>>y>>z;
		map[x][y]=map[y][x]=z;
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=1;j<=n;j++)
		{
			ans=max(ans,map[i][j]);
		}
		if(ans<minn){k=i;minn=ans;}
	}
	cout<<k<<endl;
}
int main()
{
	init();
	floyd();
	solve();
	return 0;
}