#include<iostream>
using namespace std;
int g(int a[],int bg,int ed)
{ int i,s=0;
  for(i=bg;i<=ed;i++)s=s*10+a[i];
  return s;
}
int main()
{
 	int n,k,a[41],f[41][8],sum[16][16],m;
 	cin>>n>>k;
 	char c;
 	for(int i=1;i<=n;i++){cin>>c;a[i]=c-'0';}
 	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)sum[i][j]=g(a,i,j);
	for(int i=1;i<=n;i++)f[i][0]=sum[1][i];
	for(int j=1;j<=k;j++)
	for(int i=j+1;i<=n;i++)
	{
		m=0;
		for(int t=j;t<=i-1;t++)
				if(m<f[t][j-1]*sum[t+1][i])m=f[t][j-1]*sum[t+1][i];
		f[i][j]=m;
	}
	cout<<f[n][k];
	return 0;
}
