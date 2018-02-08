#include<iostream>
using namespace std;
long long f[15][155][110]={0},ans=0;
int n,k,num[155]={0},s[155]={0};
int main()
{
	cin>>n>>k;
	for(int i=0,t;i<(1<<n);i++)
	{
		if(i&(i<<1))continue;
		t=0;
		for(int j=0;j<n;j++)if(i&(1<<j))t++;
		s[++s[0]]=i;
		num[s[0]]=t;
	}
	f[0][1][0]=1;
	for(int i=1;i<=n;i++)
	for(int t=1;t<=s[0];t++)
	for(int kk=0;kk<=k;kk++)
	{
		if(!f[i-1][t][kk])continue;
		for(int j=1;j<=s[0];j++)
		{
			if((s[t]&s[j])||(s[t]&(s[j]<<1))||(s[t]&(s[j]>>1)))continue;
			if(num[j]+kk>k)continue;
			f[i][j][kk+num[j]]+=f[i-1][t][kk];
		}
	}
	for(int i=1;i<=s[0];i++)ans+=f[n][i][k];
	cout<<ans<<endl;
	return 0;
}