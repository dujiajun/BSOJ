#include<iostream>
using namespace std;
int n,a[35]={0};
void p(int k)
{
	for(int i=1;i<k;i++)cout<<a[i]<<"+";
	cout<<a[k]<<endl;
}
void dfs(int x,int k)
{
	if(x==1)return;
	for(int i=a[k-1];i<=x/2;i++)
	{
		a[k]=i;
		a[k+1]=x-i;
		p(k+1);
		dfs(x-i,k+1);
	}
}
int main()
{
	cin>>n;
	a[0]=1;
	dfs(n,1);
	return 0; 
}