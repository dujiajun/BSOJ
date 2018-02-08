#include<iostream>
using namespace std;
int n,a[5005]={0},b[5005]={0},ans=0,len=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	for(int i=1;i<n-ans;i++)
	for(int j=i+ans;j<n-ans;j++)
	if(b[i]==b[j])
	{
		len=1;while(b[i+len]==b[j+len]&&i+len+1<j)len++;
		ans=max(ans,len);
	}
	if(ans<4)ans=-1;
	cout<<ans+1<<endl;
	return 0;
}