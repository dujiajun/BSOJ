#include<iostream>
using namespace std;
int v[205]={0},f[100005];
int main()
{
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{cin>>v[i];}
	for(int i=1;i<=m;i++)f[i]=100000; 
	for(int i=1;i<=n;i++)
		for(int j=v[i];j<=m;j++)
			f[j]=min(f[j],f[j-v[i]]+1);
	for(int i=1;i<=m;i++)
		if(f[i]==100000)cout<<-1;
		else cout<<f[i]<<endl;
	return 0;
}