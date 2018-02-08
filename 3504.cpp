#include<iostream>
#include<algorithm>
using namespace std;
int n,l,pos,x[1005],f[1005][1005][2];
int main()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)cin>>x[i];
	n++;x[n]=l;
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
		if(x[i]==l)pos=i;
		for(int j=1;j<=n;j++)f[i][j][0]=f[i][j][1]=1<<30;
	}
	f[pos][pos][0]=f[pos][pos][1]=0;
	for(int i=pos;i>=1;i--)
	for(int j=pos;j<=n;j++)
	{
		f[i][j][0]=min(f[i+1][j][0]+(x[i+1]-x[i])*(n-j+i),f[i][j][0]);
		f[i][j][0]=min(f[i][j][0],f[i+1][j][1]+(x[j]-x[i])*(n-j+i));
		f[i][j][1]=min(f[i][j][1],f[i][j-1][1]+(x[j]-x[j-1])*(n-j+i));
		f[i][j][1]=min(f[i][j-1][0]+(x[j]-x[i])*(n-j+i),f[i][j][1]);
	}
	cout<<min(f[1][n][0],f[1][n][1])<<endl;
	return 0;
}