#include<iostream>
using namespace std;
int a[201][201],ans=0;
int main()
{
	int n,m,k,j;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{cin>>j>>k;a[j][k]=1;}
	cin>>k;
	for(int i=1;i<=n;i++)if(a[k][i])ans++;
	cout<<ans<<endl;
	return 0;
}