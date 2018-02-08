#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[10][10][10][10];
int map[10][10];
int main()
{
 int n;
 int x,y,z;
 cin>>n;
 while(1)
  {
   scanf("%d%d%d",&x,&y,&z);
   if(x==0&&y==0&&z==0) break;
   map[x][y]=z;
  }
 memset(f,0,sizeof(f));
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   for(int k=1;k<i+j;k++)
   {
      f[i][j][k][i+j-k]=max(max(f[i-1][j][k-1][i+j-k],f[i-1][j][k][i+j-k-1]),
                          max(f[i][j-1][k-1][i+j-k],f[i][j-1][k][i+j-k-1]))
                          +map[i][j]+map[k][i+j-k];

         if(i==k) f[i][j][k][i+j-k]-=map[i][j];}
        cout<<f[n][n][n][n];
        return 0; 
}