#include<iostream>
using namespace std;
int n,a[10]={0},m,ans=0;
void dp(int k)
{
	if(n==0)return;
	if(k==m){if(n>=a[k-1])ans++;return;}
	for(int i=a[k-1];i<=n/(m-k+1);i++)
	{
		a[k]=i;
		n=n-i;
		dp(k+1);
		n=n+i;
	}	
}
int main()
{
 	cin>>n>>m;
 	a[0]=1;
 	dp(1);
 	cout<<ans;
	return 0;
}
