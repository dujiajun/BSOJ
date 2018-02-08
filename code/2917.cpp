#include<iostream>
#include<cstdio>
using namespace std;
int n,m,r,c,s[1001][1001]={0},x,maxx=0;
int main()
{
 	scanf("%d%d%d%d",&n,&m,&r,&c);
 	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
 	    scanf("%d",&x);
		s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
    }
 	for(int i=r;i<=n;i++)
	for(int j=c;j<=m;j++)
		maxx=max(maxx,s[i][j]-s[i-r][j]-s[i][j-c]+s[i-r][j-c]);
	printf("%d",maxx);
	return 0;
}
