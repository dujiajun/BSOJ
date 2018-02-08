#include<iostream>
using namespace std;
long long n,a[200010][4],f[200010][4]={0};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++)
	{
		f[i][1]=min(f[i-1][2],f[i-1][3])+a[i][1];
		f[i][2]=min(f[i-1][1],f[i-1][3])+a[i][2];
		f[i][3]=min(f[i-1][1],f[i-1][2])+a[i][3];
	}
	cout<<min(f[n][1],min(f[n][3],f[n][2]))<<endl;
	return 0;
}