#include<iostream>
using namespace std;
const int INF=0x7fffffff;
int cost[11]={0},n,f[101]={0};
void init()
{
	for(int i=1;i<=10;i++)cin>>cost[i];
	cin>>n;
}
void dp()
{
	for(int i=1;i<=n;i++)f[i]=INF;
	f[0]=0;f[1]=cost[1];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=10;j++)
		if(i-j>=0&&f[i]>f[i-j]+cost[j])f[i]=f[i-j]+cost[j];	
	cout<<f[n]<<endl;
}
int main()
{
	init();
	dp();
	return 0;
}
/*
12 21 31 40 49 58 69 79 90 101
15
*/