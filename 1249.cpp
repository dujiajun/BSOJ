#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n,m,x[105],y[105],s,t;
double map[105][105];
double dis(int a,int b,int c,int d)
{return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)map[i][j]=1<<29;
	for(int i=1;i<=n;i++)
	{
		map[i][i]=0;
		cin>>x[i]>>y[i];
	}
	cin>>m;
	for(int i=1,a,b;i<=m;i++)
	{
		cin>>a>>b;
		map[a][b]=map[b][a]=dis(x[a],y[a],x[b],y[b]);
	}
	cin>>s>>t; 
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
	cout<<fixed<<setprecision(2)<<map[s][t];
	return 0;
}