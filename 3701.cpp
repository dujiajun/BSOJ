#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,l,a[2005]={0},b[2005]={0},t=1,f[2005],c[2005]={0},rmq[2005][15],ans=1<<29;
void st()
{
	int t=log2(n);
	for(int i=1;i<=n;i++)rmq[i][0]=a[i];
	for(int j=1;j<=t;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
inline int ask(int l,int r)
{
	int t=log2(r-l+1);
	return max(rmq[l][t],rmq[r+1-(1<<t)][t]);
}
int main()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		b[i]+=b[i-1];
	}
	st();
	for(int i=0;i<=n;i++)f[i]=1<<29;
	f[0]=0;f[1]=a[1];
	for(int i=1;i<=n;i++)
	for(int j=0;j<=i-1;j++)
	if(b[i]-b[j]<=l)f[i]=min(f[i],f[j]+ask(j+1,i)); 
	cout<<f[n]<<endl;
	return 0;
} 
/*
5 10
5 7
9 2
8 5
13 2
3 8
*/