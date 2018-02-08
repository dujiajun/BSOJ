#include<iostream>
#include<cstring>
using namespace std;
char s[200],b[6][10],g[100][100];
int f[1000][6]={0},n1;
bool com(int x,int e,int j)
{
    for(int i=0;i<strlen(b[j]);i++)
        if(x+i>e||s[x+i]!=b[j][i])return false;
    return true;  
}
int word(int x,int e)
{   int i,j,c=0;
    for(int i=x;i<=e;i++)
        for(int j=0;j<n1;j++)if(com(i,e,j)){c++;break;} 
    return c;   
}
int main()
{  
    int n,k,i,j,w,maxx;
    cin>>n>>k;n*=20;
    for(int i=1;i<=n;i++)cin>>s[i]; cin>>n1;
    for(int i=0;i<n1;i++)cin>>b[i];
    for(int i=1;i<=k;i++)
      for(int j=i;j<=n-k+i;j++)
      { 
        maxx=0;
        for(int w=i-1;w<=j-1;w++)
          if(maxx<f[w][i-1]+word(w+1,j))maxx=f[w][i-1]+word(w+1,j);
        f[j][i]=maxx;
      }   
    cout<<f[n][k];  
    return 0;
}  
