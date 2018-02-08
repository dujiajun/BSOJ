#include<iostream>
using namespace std;
int a[80005]={0},b[80005]={0},n,m,minn=80005,maxx=0,bj=0;
int main()
{
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		a[x+40000]++;
		minn=min(x+40000,minn);
		maxx=max(x+40000,maxx);
	}
	cin>>m;
	for(int i=1,x;i<=m;i++)
	{
		cin>>x;
		b[x+40000]++;
		minn=min(x+40000,minn);
		maxx=max(x+40000,maxx);
	}
	for(int i=minn;i<=maxx;i++)if(a[i]&&b[i])
	{
		cout<<i-40000<<" ";bj=1;
	}
	if(!bj)cout<<"nil\n";
	else cout<<endl;
	bj=0;
	for(int i=minn;i<=maxx;i++)if(a[i]||b[i])
	{
		cout<<i-40000<<" ";bj=1;
	}
	if(!bj)cout<<"nil\n";
	else cout<<endl;
	bj=0;
	for(int i=minn;i<=maxx;i++)if(a[i]&&!b[i])
	{
		cout<<i-40000<<" ";bj=1;
	}
	if(!bj)cout<<"nil\n";
	else cout<<endl;
	return 0;
} 