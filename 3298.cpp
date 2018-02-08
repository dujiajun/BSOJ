#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[1000011]={0},maxx=0;
int Find(int low,int high)
{
	if(low==high)return low;
	int mid=(low+high+1)/2;
	long long sum=0;
	for(int i=1;i<=n;i++)if(a[i]>mid)sum+=a[i]-mid;
	if(sum>=m)return Find(mid,high);
	else return Find(low,mid-1);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	cout<<Find(0,maxx)<<endl;
	return 0;
}
/*
5 20
4 42 40 26 46
*/