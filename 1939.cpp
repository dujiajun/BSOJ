#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1000005],f[1000005][20],n,k;
void pre()
{
	int t=log2(n);
	for(int i=1;i<=n;i++)f[i][0]=a[i];
	for(int j=1;j<=t;j++)
		for(int i=1;i+(1<<j)<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int find(int l,int r)
{
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	pre();
	for(int i=1,a,b;i<=k;i++)
	{
		scanf("%d%d",&a,&b);;
		cout<<find(a,b)<<endl;
	}
	return 0;
} 
/*
10 2
3 2 4 5 6 8 1 2 9 7
1 8
2 9
*/