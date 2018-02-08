#include<iostream>
using namespace std;
const int INF=0x7fffffff/2;
int n,m,a[15]={0},f[10005][15];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)f[i][0]=INF;
	for(int j=1;j<=n;j++)
	for(int i=0;i<=m;i++)
	{
		f[i][j]=INF;
		for(int k=1;k*k<=i;k++)f[i][j]=min(f[i][j],(k-a[j])*(k-a[j])+f[i-k*k][j-1]);
	}
	if(f[m][n]==INF)cout<<-1<<endl;
	else cout<<f[m][n]<<endl;
	return 0;
}