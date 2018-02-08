#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int f[5005][5005];
string s;
int main()
{
	int n,ans=0;
	cin>>n>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){f[0][i]=n-i+1;f[i][n+1]=i;}
	for(int i=1;i<=n;i++)
	for(int j=n;j>=i;j--)
	{
		if(s[i]==s[j])f[i][j]=f[i-1][j+1];
		else f[i][j]=min(f[i-1][j],f[i][j+1])+1;
	}
	ans=0xfffffff;
	for(int i=0;i<=n;i++)
	{
		if(f[i][i+1]<ans)ans=f[i][i+1];
		if(f[i][i]<ans&&i>0)ans=f[i][i];
	}
	cout<<ans;
}