#include<iostream>
using namespace std;
int n,stn[105],f[105],fmin[101][101]={0},a[105],ans=0x7fffffff/2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>stn[i];
	for(int m=1;m<=n-1;m++)
	{
		for(int o=1;o<=n;o++)a[o]=stn[o];
		swap(a[m],a[m+1]);
		for(int i=1;i<=n;i++)
			f[i]=f[i-1]+a[i];
		for(int t=1;t<=n;t++)
		for(int i=1;i<=n-t;i++)
		{
			int j=i+t;
			fmin[i][j]=0x7fffffff/2;
			for(int k=i;k<j;k++)
	    		fmin[i][j]=min(fmin[i][k]+fmin[k+1][j],fmin[i][j]);
	    	fmin[i][j]+=f[j]-f[i-1];
		}
		ans=min(ans,fmin[1][n]);
	}
	cout<<ans;
	return 0;
}