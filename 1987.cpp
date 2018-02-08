#include<iostream>
#include<cstdlib>
using namespace std;
int n,h,f[200][300]={0},fi[200]={0},dw[200]={0},t[200]={0};
void init()
{
	cin>>n>>h;
	h*=12;
	for(int i=1;i<=n;i++)cin>>fi[i];
	for(int i=1;i<=n;i++)cin>>dw[i];
	for(int i=2;i<=n;i++)cin>>t[i];
}
void dp()
{
	int go=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		go+=t[i];
		for(int j=go;j<=h;j++)
			for(int k=0;k<=j-go;k++)
			{
				if(fi[i]-(k-1)*dw[i]<0)break;
				int all=(fi[i]+fi[i]-(k-1)*dw[i])*k/2;
				f[i][j]=max(f[i][j],f[i-1][j-t[i]-k]+all);
				ans=max(ans,f[i][j]);
			}
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	dp();
	return 0;
}
/*
3
1
4 5 6
1 2 1
1 2
*/
/*
2
1
10 1
2 5
2
*/
