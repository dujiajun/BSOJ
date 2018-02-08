#include<iostream>
using namespace std;
long long n,ans=0,a[10005]={0},s[10005]={0};
void dfs(int dp)
{
	if(dp==n+1&&a[n]+a[n-1]==s[n])
	{
	  	ans++;
	  	return;
	}
	for(int i=0;i<=1;i++)
	{
	   a[dp]=i;
       if(dp==1)dfs(dp+1);
       if(dp>=3&&a[dp]+a[dp-1]+a[dp-2]==s[dp-1])dfs(dp+1);
       if(dp==2&&a[dp]+a[dp-1]==s[dp-1])dfs(dp+1);
   }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    dfs(1);
    cout<<ans<<endl;
	return 0;
}