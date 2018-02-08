#include<iostream>
using namespace std;
int n,m,a[1000005],x,sum,ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,j=1;i<=n;i++)
	{
		sum-=a[i-1];
		if(i>j)j=i;
		while(j<=n&&sum+a[j]<=m){sum+=a[j];j++;}
		ans=max(ans,j-i);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 10
2 3 1 6 7
*/