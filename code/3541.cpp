#include<iostream>
using namespace std;
long long a[101][101]={0},f[101][101]={0},t[101][101]={0};
int main()
{
 	int n,m,l,k;
 	cin>>n>>m;
 	string s;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>s;
 		for(int j=1;j<=m;j++)a[i][j]=s[j-1]-'0';
 	}
 	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
 	 		 f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
 	for(int i=1;i<=n;i++)t[i][1]=1;
 	for(int i=1;i<=m;i++)t[1][i]=1;
 	for(int i=2;i<=n;i++)
	 for(int j=2;j<=m;j++)
	 {
		if(f[i][j]==f[i-1][j]+a[i][j])
		l=1;else l=0;
		if(f[i][j]==f[i][j-1]+a[i][j])
		k=1;else k=0;
		t[i][j]=t[i-1][j]*l+t[i][j-1]*k;
	}
	cout<<f[n][m]<<endl<<t[n][m];
   	return 0;
}
