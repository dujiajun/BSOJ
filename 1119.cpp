#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,g[101]={0},x,f[101][101]={0};
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++){cin>>x;g[i]=g[i-1]+x;}
}
int hbmin(int i,int j)
{
	if(i==j)return 0;
	if(f[i][j]>0)return f[i][j];
	int s=0xfffffff;
	for(int k=i;k<j;k++)
	{s=min(s,hbmin(i,k)+hbmin(k+1,j));}
	s+=g[j]-g[i-1];
	f[i][j]=s;
	return s;
}
int hbmax(int i,int j)
{
	if(i==j)return 0;
	if(f[i][j]>0)return f[i][j];
	int s=0;
	for(int k=i;k<j;k++)
	{s=max(s,hbmax(i,k)+hbmax(k+1,j));}
	s+=g[j]-g[i-1];
	f[i][j]=s;
	return s;
}
int main()
{
	init();
	cout<<hbmin(1,n)<<endl;
	memset(f,0,sizeof(f));
	cout<<hbmax(1,n);
	return 0;
}