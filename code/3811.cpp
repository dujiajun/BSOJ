#include<iostream>
#include<cmath>
using namespace std;
const int MOD=1000000007;
int n,k,pr[1000005];
long long ans=1,tmp,cnt;
bool vst[1000005];
void mkpr()
{
	for(int i=2;i<=n;i++)
	{
		if(!vst[i])pr[++k]=i;
		for(int j=1;j<=k&&i*pr[j]<=n;j++)
		{
			vst[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
}
int main()
{
	cin>>n;
	mkpr();
	for(int i=1;i<=k;i++)
	{
		tmp=pr[i];cnt=0;
		while(tmp<=n){cnt+=n/tmp*2;tmp*=pr[i];}
		ans=(ans*(cnt+1))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}