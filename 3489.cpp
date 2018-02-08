#include<iostream>
using namespace std;
int ans=0x7fffffff,n,a[300];
void dfs(int dp,int b1,int b2,int b3)
{
	if(dp==n+1){ans=max(max(b1,b2),b3);return;}
	if(b1+a[dp]<=ans)dfs(dp+1,b1+a[dp],b2,b3);
	if(b2+a[dp]<=ans&&b1!=b2)dfs(dp+1,b1,b2+a[dp],b3);
	if(b3+a[dp]<=ans&&b1!=b3&&b2!=b3)dfs(dp+1,b1,b2,b3+a[dp]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}