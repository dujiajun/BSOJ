#include<iostream>
using namespace std;
int map[105][105]={0},n,m;
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)map[i][j]=1<<29;
			else map[i][j]=0;
	for(int i=1,a,b,v;i<=m;i++)
	{
		cin>>a>>b>>v;
		map[a][b]=map[b][a]=v;
	}
}
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}
int main()
{
	init();
	floyd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<map[i][j]<<" ";
		cout<<endl; 
	}
	return 0;
}