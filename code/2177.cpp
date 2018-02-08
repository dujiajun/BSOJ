#include<iostream>
using namespace std;
int n,k,f[1005][1005]={0},a[1005]={0},b[1005]={0},w[1005][1005]={0};
char c;
int main()
{
	//freopen("horse.in","r",stdin);
	//freopen("horse.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='1'){a[i]=a[i-1]+1;b[i]=b[i-1];}
		else {b[i]=b[i-1]+1;a[i]=a[i-1];}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=k;j++)f[i][j]=1<<29;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)w[i][j]=(a[j]-a[i-1])*(b[j]-b[i-1]);
		f[i][1]=w[1][i];f[i][i]=0;
	}
	for(int j=1;j<=k;j++)
	for(int i=j;i<=n;i++)
	for(int p=j-1;p<=i-1;p++)
	if(p>0&&f[p][j-1]!=1<<29&&j>=2)f[i][j]=min(f[i][j],f[p][j-1]+w[p+1][i]);
	cout<<f[n][k]<<endl; 
	return 0;
}