#include<iostream>
using namespace std;
int n,m,t,map[305][305];
int main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)map[i][j]=1<<30;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z); 
		map[x][y]=z;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)map[i][j]=min(map[i][j],max(map[i][k],map[k][j]));
	for(int i=1,x,y;i<=t;i++)
	{
		scanf("%d%d",&x,&y);
		if(map[x][y]!=1<<30)printf("%d\n",map[x][y]);
		else printf("-1\n");
	}
	return 0;
}
/*
5 6 3
1 2 12
3 2 8
1 3 5
2 5 3
3 4 4
2 4 8
3 4
1 2
5 1
*/