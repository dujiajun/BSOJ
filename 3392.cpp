#include<iostream>
using namespace std;
long long n,a[5005],f[5005],k;
double minn;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=1<<29;minn=1<<29;
		for(int j=i-1;j>=max(1ll,i-k);j--)
		if(double(a[i]-a[j])/double(i-j)<=minn&&i-j<=k)//斜率 
		{
			f[i]=min(f[j]+1,f[i]);
			minn=double(a[i]-a[j])/double(i-j);
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
/*
13 4
0
1
0
2
4
6
8
6
8
8
9
11
12
*/