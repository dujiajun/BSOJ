#include<iostream>
using namespace std;
const int INF=0x7fffffff;
int m,kk,a[101]={0},f[101][101]={0},tag[101][101]={0};//f[i][j]表示第i个人抄第j本书所需的时间 
void init()
{
	cin>>m>>kk;//m表示书的数量，k表示人数 
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
		f[1][i]=a[i];
	}
}
void out(int s,int t)
{
	if(s==1)cout<<1<<" "<<t<<endl;
	else
	{
		out(s-1,tag[s][t]);
		cout<<tag[s][t]+1<<" "<<t<<endl;
	}
}
void dp()
{
	for(int i=2;i<=kk;i++)
	for(int j=i;j<=m;j++)
	{
		f[i][j]=INF;
		for(int k=i-1;k<j;k++)
			if(max(a[j]-a[k],f[i-1][k])<f[i][j])
			{
				f[i][j]=max(a[j]-a[k],f[i-1][k]);
				tag[i][j]=k;
			}	
	}
	cout<<f[kk][m]<<endl;
	out(kk,m);
}
int main()
{
	init();
	dp();
	return 0;
}
/*
9 3
1 2 3 4 5 6 7 8 9
*/