#include<iostream>
using namespace std;
int n,f[101],s=0,b[101]={0},c[101]={0},d[101]={0};
void dfs(int k)
{
	if(k>n){s++;for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;return;}
	for(int i=1;i<=n;i++)
		if(b[i]==0&&c[k-i+n]==0&&d[k+i]==0)
		{
			f[k]=i;
			b[i]=1;c[k-i+n]=1;d[k+i]=1;
			dfs(k+1);
			b[i]=0;c[k-i+n]=0;d[k+i]=0;
		}
	return;
}
int main()
{
	cin>>n;
	if(n>1&&n<=3)cout<<"no solute!"<<endl;
	dfs(1);
	return 0;
}