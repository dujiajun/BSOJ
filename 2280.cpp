#include<iostream>
using namespace std;
int a[100005][5]={0},f[5][5]={0},n,ans=0;
void dp(int x)
{
	for(int i=1;i<=4;i++)f[1][i]=0;
	f[1][x]=a[1][x/2+1];
	for(int i=2;i<=n;i++)
	{
		f[i%4][1]=max(f[(i-1)%4][4],f[(i-1)%4][3])+a[i][1];
		f[i%4][2]=f[(i-1)%4][4]+a[i][2];
		f[i%4][3]=f[(i-1)%4][1]+a[i][2];
		f[i%4][4]=max(f[(i-1)%4][1],f[(i-1)%4][2])+a[i][3];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	dp(1);
	ans=max(f[n%4][3],f[n%4][4]);
	dp(2);
	ans=max(ans,f[n%4][4]);
	dp(3);
	ans=max(ans,f[n%4][1]);
	dp(4);
	ans=max(ans,max(f[n%4][1],f[n%4][2]));
	cout<<ans<<endl;
	return 0;
}
/*
4
1 3 2
3 1 2
3 1 2
3 1 2
*/