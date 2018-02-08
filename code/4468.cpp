#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t,xi[100005],yi[100005],e[100005],tmp[200050],a[200005],prt[200005];
int bj;
int bfind(int num)
{
	int l=1,r=a[0],mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]>=num)r=mid;
		else l=mid+1;
	}
	return l;
}
int getfa(int fa)
{
	if(fa==prt[fa])return fa;
	prt[fa]=getfa(prt[fa]);
	return prt[fa];
}
void todo()
{
	memset(tmp,0,sizeof(tmp));
	memset(a,0,sizeof(a));
	memset(xi,0,sizeof(xi));
	memset(yi,0,sizeof(yi));
	bj=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>xi[i]>>yi[i]>>e[i];
		tmp[++tmp[0]]=xi[i];
		tmp[++tmp[0]]=yi[i];
	}
	sort(tmp+1,tmp+tmp[0]+1);
	for(int i=1;i<=tmp[0];i++)if(tmp[i]!=tmp[i-1])a[++a[0]]=tmp[i];
	for(int i=1;i<=a[0];i++)prt[i]=i;
	for(int i=1;i<=n;i++)
	{
		xi[i]=bfind(xi[i]);
		yi[i]=bfind(yi[i]);
	}
	for(int i=1;i<=n;i++)
	if(e[i]==1)
	{
		int f1=getfa(xi[i]),f2=getfa(yi[i]);
		if(f1!=f2)prt[f1]=f2;
	}
	for(int i=1;i<=n;i++)
	if(e[i]==0)
	{
		int f1=getfa(xi[i]),f2=getfa(yi[i]);
		if(f1==f2){bj=1;break;}
	}
	if(bj==1)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
int main()
{
	cin>>t;
	while(t--)
	{
		todo();
	}
	return 0;
}
/*
2
2
1 2 0
1 2 1
2 
1 2 1
2 1 1

2
3
1 2 1
2 3 1
3 1 1
4
1 2 1
2 3 1
3 4 1
1 4 0
*/