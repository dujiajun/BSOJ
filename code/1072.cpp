#include<iostream>
using namespace std;
int dy[8]={1,2,2,1,-1,-2,-2,-1},dx[8]={-2,-1,1,2,2,1,-1,-2}; 
int x,y,m,n,i,j,g[21][21]={0};
long long f[21][21]={0};
int main()
{	
   cin>>n>>m>>x>>y;
   g[x][y]=1;
   for(i=0;i<8;i++)
   {  
   	  int xx=x+dx[i],yy=y+dy[i];
	  if(xx>=0&&xx<=n&&yy>=0&&yy<=m)g[xx][yy]=1;
   }
   f[0][0]=1;
   for(i=1;i<=n;i++)if(g[i][0]==0)f[i][0]=f[i-1][0];
   for(i=1;i<=m;i++)if(g[0][i]==0)f[0][i]=f[0][i-1];
   for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)if(g[i][j]==0)f[i][j]=f[i-1][j]+f[i][j-1];
   cout<<f[n][m];
   return 0;
}
