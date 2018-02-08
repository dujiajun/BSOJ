#include<iostream>
using namespace std;
int a[101][101],f[101][101];
void out(int i,int j)
{
	if(i==0)return ;
	if(f[i][j]==f[i][j-1])out(i,j-1);
	else {
		out(i-1,j-1);
		cout<<j<<" ";
	}
}
int main()
{
    int fn,v;
    cin>>fn>>v;
    for(int i=1;i<=fn;i++)
      for(int j=1;j<=v;j++)cin>>a[i][j];
    for(int i=1;i<=fn;i++)
      for(int j=0;j<=v;j++)f[i][j]=-0x7fffffff/2;
    for(int i=1;i<=fn;i++)
    for(int j=1;j<=v;j++)
    for(int k=i;k<=j;k++)
    	f[i][j]=max(f[i][j],f[i-1][k-1]+a[i][k]);
    cout<<f[fn][v]<<endl;
    out(fn,v);
	return 0;
}
