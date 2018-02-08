#include<iostream>
using namespace std;
const int INF=0x7fffffff/2;
int n,map[1005][1005],ans;
int main()
{    
	cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)map[i][j]=INF;
    for(int i=1,x,y,z;i<=n-1;i++)
	{
		cin>>x>>y>>z;
		map[x][y]=map[y][x]=z;
	}
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(map[i][k]!=INF&&map[k][j]!=INF&&map[i][k]+map[k][j]<map[i][j])map[i][j]=map[i][k]+map[k][j];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)if(i!=j&&map[i][j]>ans)ans=map[i][j];
    cout<<ans;
    return 0;
}