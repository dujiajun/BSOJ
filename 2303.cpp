#include<iostream>
using namespace std;
int n,a[1010],map[1010][1010],bj=1,c[1010]={0},f[1010]={0},minn=1,num[1010]={0},in[1010]={0};
void dfs(int x)
{
	for(int i=1;i<=n&&bj;i++)
	if(map[x][i])
	{
		if(c[i]==0)
		{
			c[i]=3-c[x];
			dfs(i);
		}
		else if(c[i]!=3-c[x]){bj=0;return;}
	}
}
void out()
{
	int i=1;
	for(i=1;i<=n;i++)num[a[i]]=i;
	i=1;
	while(1)
	{
		while(in[minn])
		{
			if(c[num[minn]]<=1)cout<<"b ";
			else cout<<"d ";
			minn++;
		}
		if(minn>n)return;
		in[a[i]]=1;
		if(c[i]<=1)cout<<"a ";
		else cout<<"c ";
		i++;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[n]=0x7fffffff;
	for(int i=n-1;i>=1;i--)f[i]=min(f[i+1],a[i+1]);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(a[i]<a[j]&&a[i]>f[j])map[i][j]=map[j][i]=1;
	for(int i=1;i<=n&&bj;i++)if(c[i]==0){c[i]=1;dfs(i);}
	if(bj)out();
	else cout<<0<<endl;
	return 0;
}