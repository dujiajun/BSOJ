#include<iostream>
using namespace std;
int n,m,in[201]={0},f[201][201]={0},a[201],ans=0;
void init()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		in[y]++;
		f[x][y]=1;
	}
}
bool topsort()
{
	int j=1;
	for(int i=1;i<=n;i++)
	{
		j=1;
		while(in[j]&&j<=n)j++;
		if(j>n){cout<<"no solution"<<endl;return false;}
		ans++;in[j]=-1;a[ans]=j;
		for(int k=1;k<=n;k++)
			if(f[j][k]==1)in[k]--;
	}
	return true;
}
int main()
{
	init();
	if(topsort())
		for(int i=1;i<=ans;i++)cout<<a[i]<<" ";
	return 0;
}