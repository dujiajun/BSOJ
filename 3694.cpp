#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[100005],b[100005];
long long ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		ans+=abs(a[i]-b[i]);
	}
	a[n+1]=m;b[n+1]=0;
	sort(a+1,a+n+2);
	sort(b+1,b+n+2);
	for(int i=1;i<=n+1;i++)ans+=abs(a[i]-b[i]);
	cout<<ans<<endl;
	return 0;
}