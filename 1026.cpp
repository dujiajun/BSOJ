#include<iostream>
using namespace std;
int n,a[1005],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(a[i]>a[j]){swap(a[i],a[j]);ans++;}
	cout<<ans<<endl;
	return 0;
}