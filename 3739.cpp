#include<iostream>
using namespace std;
int n,a[100000]={0},h[100000]={0};
long long ans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[n-i+1]);
	for(int i=1;i<=n;i++)h[i]=i-1;
	a[0]=0x7fffffff;
	for(int i=1;i<=n;i++)while(a[i]>a[h[i]])h[i]=h[h[i]];
	for(int i=1;i<=n;i++)ans+=i-h[i]-1;
	cout<<ans<<endl;
	return 0;
}