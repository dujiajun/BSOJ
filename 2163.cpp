#include<iostream>
using namespace std;
int n,k,a[101]={0},fa[101]={0},mo[101]={0},f[101][101]={0},vst[101][101]={0};
void init()
{
	cin>>n>>k;
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>fa[i]>>mo[i];
}
int dp(int x,int y)
{
	int maxx=-999999;
	if(x==0&&y!=0)return maxx;
	if(x==0||y==0)return 0;
	if(y==1)return a[x];
	if(vst[x][y]>0)return f[x][y];
	for(int k=0;k<=y-1;k++)
		maxx=max(maxx,dp(fa[x],k)+dp(mo[x],y-k-1)+a[x]);
	f[x][y]=maxx;
	vst[x][y]=1;
	return f[x][y];
}
int main()
{
	init();
	cout<<dp(1,k+1);
	return 0;
}
/*
6 3
-2 3 -2 3 -1
2 3
4 5
0 6
0 0
0 0
0 0
*/