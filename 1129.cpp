#include<iostream>
using namespace std;
const int INF=0xfffffff;
int n,map[105][105]={0},nc[105]={0},ans=INF;
void sovle()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(map[i][k]+map[k][j]<map[i][j])
			map[i][j]=map[i][k]+map[k][j];
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		maxx=0;
		for(int j=1;j<=n;j++)maxx+=nc[j]*map[i][j];
		ans=min(maxx,ans);
	}
	cout<<ans<<endl;
}
void init()
{
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(i!=j)map[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		cin>>nc[i]>>x>>y;
		if(x!=0){map[i][x]=1;map[x][i]=1;}
		if(y!=0){map[i][y]=1;map[y][i]=1;}
	}
}
int main()
{
	init();
	sovle();
	return 0;
}
/*
5
13 2 3
4 0 0
12 4 5
20 0 0
40 0 0
*/