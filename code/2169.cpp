#include<iostream>
using namespace std;
int t,n,m,a[202],b[202],f[202][202]={0},la,lb;
void git(int i,int j)
{
	la=i-1;lb=j-1;
	while(a[i]!=b[lb]&&lb>0)lb--;
	while(b[j]!=a[la]&&la>0)la--;
}
void doit()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		f[i][j]=max(f[i-1][j],f[i][j-1]);
		git(i,j);
		if(la&&lb&&a[la]!=b[lb])f[i][j]=max(f[i][j],f[la-1][lb-1]+2);
	}
	cout<<f[n][m]<<endl;
}
int main()
{
 	cin>>t;
 	for(int i=1;i<=t;i++)doit();
	return 0;
}
