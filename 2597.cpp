#include<iostream>
using namespace std;
int n,t,ans=1,map[1050][1050];
double f[1050][15];
int main() 
{
	cin>>n;t=1<<n;
	for(int i=1;i<=t;i++)
	for(int j=1;j<=t;j++)scanf("%d",&map[i][j]);
	for(int i=1;i<=t;i++)f[i][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;(j<<i)<=t;j++)
	{
		int ll=((j-1)<<i)+1;
		int lr=ll+(1<<(i-1))-1;
		int rl=lr+1;
		int rr=(j<<i);
		for(int l=ll;l<=lr;l++)
		for(int r=rl;r<=rr;r++)
		{
			f[l][i]+=map[l][r]/100.0*f[l][i-1]*f[r][i-1];
			f[r][i]+=map[r][l]/100.0*f[r][i-1]*f[l][i-1];
		}
	}
	for(int i=1;i<=t;i++)if(f[i][n]>f[ans][n])ans=i;
	cout<<ans<<endl;
	return 0;
}
/*
2
0 90 50 50
10 0 10 10
50 90 0 50
50 90 50 0
*/