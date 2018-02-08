#include<iostream>
using namespace std;
long long n,s,f[10005]={0},c[10005]={0},d[10005]={0},minn;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&d[i]);
	f[1]=c[1]*d[1];
	for(int i=2;i<=n;i++)
	{
		minn=c[i];
		for(int j=1;j<i;j++)minn=min(minn,c[j]+s*(i-j));
		f[i]=f[i-1]+minn*d[i];
	}
	cout<<f[n]<<endl;
	return 0;
}