#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1001][1001]={0};
int main()
{
 	int n;
 	cin>>n;
 	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
  	  for(int i=1;i<=n;i++)
  	  {
  	  	a[1][i]+=a[1][i-1];
  	  	a[i][1]+=a[i-1][1];
  	  }
  	for(int i=2;i<=n;i++)
	  for(int j=2;j<=n;j++)
 		a[i][j]=min(a[i][j-1],a[i-1][j])+a[i][j];
	cout<<a[n][n];
	return 0;
}
