#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod=10007;
long long n,m,a[305]={0},ans=1,c[30010][305]={0};
int main()
{
	//freopen("poker.in","r",stdin);
	//freopen("poker.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=10000;i++)c[i][0]=1;
	for(int i=1;i<=10000;i++)c[i][1]=i;
	for(int i=2;i<=10000;i++)
	for(int j=2;j<=100;j++)if(i==j)c[i][j]=1;else if(i>j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	for(int k=1;k<=m;k++)//C(n,m)=C(n-1,m-1)+C(n,m-1);
	{
		ans=(ans*c[n][a[k]])%mod;
		n-=a[k];
	}
	cout<<ans<<endl;
	return 0;
}