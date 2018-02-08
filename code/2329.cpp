#include<iostream>
using namespace std;
int l[4],c[4],s,t,n,loca[105]={0},f[105][105]={0};
int prc(int s1,int s2)
{
	int dis=loca[s2]-loca[s1];
	if(dis>0&&dis<=l[1])return c[1];
	if(dis>l[1]&&dis<=l[2])return c[2];
	if(dis>l[2]&&dis<=l[3])return c[3];
	return 0x7fffffff/2;
}
void init()
{
	cin>>l[1]>>l[2]>>l[3]>>c[1]>>c[2]>>c[3]; 
	cin>>n;
	cin>>s>>t;
	for(int i=2;i<=n;i++)cin>>loca[i];
}
void dp()
{
	if(s>t)swap(s,t);
	if(s==t){cout<<0;return;}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j)f[i][j]=0x7fffffff/2;
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{
		for(int k=i;k<=j;k++)
		f[i][j]=min(f[i][k]+prc(k,j),f[i][j]);
	}
	cout<<f[s][t];
} 
int main()
{
	init();
	dp();
	return 0;
}
/*
3 6 8 20 30 40
7
2 6
3
7
8
13
15
23
*/