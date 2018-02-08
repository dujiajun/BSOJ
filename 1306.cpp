#include<iostream>
using namespace std;
int n,map[105][105]={0},ans=1<<29,sp=0;
void floyd()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}
void init()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j)map[i][j]==1<<29;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		cin>>map[i][j];
}
int main()
{
	init();
	floyd();
	for(int i=1,t=0;i<=n;i++,t=0)
	{
		for(int j=1;j<=n;j++)t+=map[i][j];
		if(ans>t){ans=t;sp=i;}
	}
	cout<<sp<<" "<<ans;
	return 0;
}