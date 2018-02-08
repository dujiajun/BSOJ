#include<iostream>
using namespace std;
int n,f[10],used[10];
void p()
{
	for(int i=1;i<=n;i++)cout<<f[i]<<" ";
	cout<<endl;
}
void dfs(int dp)
{
	if(dp>n){p();return;}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==1)continue;
		f[dp]=i;
		used[i]=1;
		dfs(dp+1);
		used[i]=0;
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}