#include<iostream>
using namespace std;
int n,k,num;
long long f[20][20]={0},sum[20]={0},ans=0;
void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		sum[i]=sum[i-1]+num;
		f[i][0]=sum[i];
	}
}
void dp()
{
	for(int i=1;i<=k;i++)
	for(int j=i+1;j<=n;j++)//f[i][j]表示前i个数用j个*号最大值 
	{
		ans=-1;
		for(int t=i;t<j;t++)
		{
			ans=max(f[t][i-1]*(sum[j]-sum[t]),ans);
			ans=max(f[t][i]+(sum[j]-sum[t]),ans);
		}
		f[j][i]=ans;
	}
	cout<<f[n][k];
}
int main()
{
	init();
	dp();
	return 0;
}