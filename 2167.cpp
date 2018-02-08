#include<iostream>
using namespace std;
int main()
{
 	int a[21][21]={0};
 	int m,n,maxx=0;
 	cin>>m>>n;
 	for(int i=1;i<=n;i++)
 		for(int j=1;j<=m;j++)cin>>a[i][j];
    int f[21][21]={0};
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
    	maxx=0;
    	for(int k=0;k<=j;k++)
    			if(f[i-1][k]+a[i][j-k]>maxx)maxx=f[i-1][k]+a[i][j-k];
    	f[i][j]=maxx;
    }
    cout<<f[n][m];
	return 0;
}
