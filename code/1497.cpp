#include<iostream>
#include<cstring>
using namespace std;
const int one=100000000;
int f[1005][1005][5]={0},n,k,m,a[10005];
void jia(int c[],int a[],int b[])
{
	c[0]=max(a[0],b[0]);
	for(int i=1;i<=c[0];i++)c[i]=a[i]+b[i];
	for(int i=1;i<=c[0];i++)c[i+1]+=c[i]/one,c[i]%=one;
	if(c[c[0]+1]>0)c[0]++;
}
int main()
{
	cin>>m;
	for(int kk=1;kk<=m;kk++)
	{	
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		cin>>n>>k;
		for(int i=1;i<=n;i++){cin>>a[i];a[i]=(a[i]%k+k)%k;}
		f[1][a[1]][0]=f[1][a[1]][1]=1;
		for(int i=2;i<=n;i++)
		for(int j=0;j<k;j++)jia(f[i][j],f[i-1][(j+a[i])%k],f[i-1][(j-a[i]+k)%k]);
		if(f[n][0][0]==0)cout<<"Not Divisible\n";
		else cout<<"Divisible\n";
	}
	return 0;
}
/*
2
4 7
17 5 -21 15
4 5
17 5 -21 15
*/