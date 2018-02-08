#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x7fffffff/2;
int n,k,t[200]={0},f[250][250]={INF};
void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>t[i];
}
void dp()
{
	if(n<2*(k+3)){cout<<-1<<endl;return;}
	k+=3;
	sort(t+1,t+n+1);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=k;j++)f[i][j]=INF;
	f[0][0]=0;
	for(int i=2;i<=n;i++)
	for(int j=1;j<=k;j++)
		f[i][j]=min(f[i-2][j-1]+(t[i-1]-t[i])*(t[i-1]-t[i]),f[i-1][j]);
	cout<<f[n][k];
}
int main()
{
	init();
	dp();
	return 0;
}
/*
10 1
1 1 2 3 3 3 4 6 10 20
*/