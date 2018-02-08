#include<iostream>
using namespace std;
int n,m,f[105][105][105]={0},a[105][105]={0},b[105][105]={0},num[2000]={0},p[2000]={0},ans=0;
void do_st(int i,int t)
{
	for(int j=0;j<(1<<m);j++)
	{
		if(j&(j<<1)||j&(j>>1)||j&(j<<2)||j&(j>>2)||j&t)continue;
		p[i]++;a[i][p[i]]=j;
		for(int k=0;k<m;k++)if((j>>k)%2)b[i][p[i]]++;
	}
}
int main()
{
	cin>>n>>m;char ch;
	for(int i=1,t;i<=n;i++)
	{
		t=0;
		for(int j=1;j<=m;j++){cin>>ch;t=(t<<1)+int(ch=='H');}
		do_st(i,t);
	}
	p[0]=1;
	for(int i=1;i<=p[1];i++){f[1][i][1]=b[1][i];ans=max(ans,f[1][i][1]);}
	for(int i=2;i<=n;i++)
	for(int j=1;j<=p[i];j++)
	for(int k=1;k<=p[i-1];k++)
		if(!(a[i][j]&a[i-1][k]))
			for(int l=1;l<=p[i-2];l++)
			if(!(a[i][j]&a[i-2][l])&&!(a[i-1][k]&a[i-2][l]))
			{
				f[i][j][k]=max(f[i][j][k],f[i-1][k][l]+b[i][j]);
				ans=max(ans,f[i][j][k]);
			}
	cout<<ans<<endl;
	return 0;
}
/*
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
*/