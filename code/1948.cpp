#include<iostream>
using namespace std;
struct wo{int t,a,b;}a[1001];
int n,st=1<<29,ed=0,f[1501]={0},bj;
int main()
{
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i].t>>a[i].a>>a[i].b;
 		ed=max(ed,a[i].b);
 		st=min(st,a[i].a);
 	}
 	for(int i=1;i<=ed;i++)f[i]=1<<29;
 	f[st]=0;
 	for(int i=st;i<=ed;i++)
 	{
 		bj=0;
 		for(int j=1;j<=n;j++)
 			if(a[j].a<=i&&a[j].b>=i+a[j].t)
 			{
 				f[i+a[j].t]=min(f[i+a[j].t],f[i]+a[j].t);
 				bj=1;
 			}
		if(!bj)f[i+1]=min(f[i],f[i+1]);
 	}
 	cout<<f[ed];
	return 0;
}
/*
3
15 0 25
50 0 90
45 15 70
*/