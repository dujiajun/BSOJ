#include<iostream>
using namespace std;
int n,m,a[1011][1011]={0},ans=0;
char c;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>c;
		a[i][j]=c-'0';
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j])
		{
			ans+=2;
			ans+=max(a[i][j]-a[i-1][j],0);
			ans+=max(a[i][j]-a[i][j-1],0);
			ans+=max(a[i][j]-a[i+1][j],0);
			ans+=max(a[i][j]-a[i][j+1],0);
		}
	}
	cout<<ans;
	return 0;
}