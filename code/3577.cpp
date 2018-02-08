#include<iostream>
using namespace std;
int n,m,f[200005],minn=1<<30,ans=1<<30;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&f[i]);
	for(int i=m+1;i<=n;i++)
	{
		minn=1<<30;
		for(int j=i-m;j<i;j++)minn=min(minn,f[j]);
		f[i]+=minn;
	}
	for(int i=n-m+1;i<=n;i++)ans=min(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}