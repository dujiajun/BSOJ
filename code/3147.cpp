#include<iostream>
using namespace std;
const int MOD=10007;
int n,m,a,b,k,c[1005][1005],ans;
int main()
{
	cin>>a>>b>>k>>n>>m;a%=MOD;b%=MOD;
	for(int i=1;i<=k;i++){c[i][0]=1;c[i][1]=i;c[i][i]=1;}
	for(int i=2;i<=k;i++)
	for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	ans=c[k][n];
	for(int i=1;i<=n;i++)ans=(ans*a)%MOD;
	for(int i=1;i<=m;i++)ans=(ans*b)%MOD;
	cout<<ans<<endl;
	return 0;
}