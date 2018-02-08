#include<iostream>
#include<cstdio>
using namespace std;
int l[2000005]={0},r[2000005]={0},n;
long long ans=0,a[2000005]={0};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l[i]=i-1;r[i]=i+1;
	}
	for(int i=1;i<=n;i++)while(a[i]<=a[l[i]])l[i]=l[l[i]];
	for(int i=n;i>=1;i--)while(a[i]<=a[r[i]])r[i]=r[r[i]];
	for(int i=1;i<=n;i++)if((r[i]-l[i]-1)*a[i]>ans)ans=(r[i]-l[i]-1)*a[i];
	cout<<ans<<endl;
	return 0;
}