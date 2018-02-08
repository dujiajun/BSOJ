#include<iostream>
using namespace std;
const int MAXX=0x7fffffff/2;
int a[25][25],f[25][25][25][65]={0},n,maxx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)cin>>a[i][j];
    for(int x=1;x<=n;x++)
    for(int y=1;y<=n;y++)
    for(int z=1;z<=n;z++)
    for(int k=max(x,max(y,z));k<=2*n-1;k++)
    {
        if(k-x+1>n||k-y+1>n||k-z+1>n)continue;
        maxx=-1;
        if(f[x][y][z][k-1]>maxx)maxx=f[x][y][z][k-1];
        if(f[x-1][y][z][k-1]>maxx)maxx=f[x-1][y][z][k-1];
        if(f[x-1][y-1][z][k-1]>maxx)maxx=f[x-1][y-1][z][k-1];
        if(f[x-1][y][z-1][k-1]>maxx)maxx=f[x-1][y][z-1][k-1];
        if(f[x-1][y-1][z-1][k-1]>maxx)maxx=f[x-1][y-1][z-1][k-1];
        if(f[x][y-1][z][k-1]>maxx)maxx=f[x][y-1][z][k-1];
        if(f[x][y-1][z-1][k-1]>maxx)maxx=f[x][y-1][z-1][k-1];
        if(f[x][y][z-1][k-1]>maxx)maxx=f[x][y][z-1][k-1];
        if(x==y&&y==z)f[x][y][z][k]=maxx+a[x][k-x+1];
    	else if(x==y&&x!=z)f[x][y][z][k]=maxx+a[x][k-x+1]+a[z][k-z+1];
        else if(y==z&&y!=x)f[x][y][z][k]=maxx+a[y][k-y+1]+a[x][k-x+1];
        else if(z==x&&z!=y)f[x][y][z][k]=maxx+a[z][k-z+1]+a[y][k-y+1];
        else f[x][y][z][k]=maxx+a[x][k-x+1]+a[y][k-y+1]+a[z][k-z+1];
    }
    cout<<f[n][n][n][2*n-1];
    return 0;
}