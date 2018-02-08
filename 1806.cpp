#include<iostream>
using namespace std;
int n,m,a,f[1050][35],ans=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		f[i][0]=f[i-1][0]+a%2;
		for(int j=1;j<=min(m,i);j++)
		{
			f[i][j]=max(f[i-1][j],f[i-1][j-1])+(j%2==a-1?1:0);
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
7 2
2
1
1
2
2
1
1
*/