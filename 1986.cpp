#include<iostream>
using namespace std;
int n,tt,a[50005],f[50005],q[50005];
bool check(int x)
{
	//memset(f,0,sizeof(f));
	f[0]=0;q[1]=0;int h=1,t=1;
	for(int i=1;i<=n+1;i++)
	{
		while(q[h]<i-x-1&&h<t)h++;
		f[i]=f[q[h]]+a[i];
		while(f[i]<=f[q[t]]&&h<t)t--;
		q[++t]=i;
	}
	if(f[n+1]<=tt)return 1;
	return 0;
}
int main()
{
	cin>>n>>tt;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
} 
/*
17 11
6 4 5 2 5 3 4 5 2 3 4 5 2 3 6 3 5
*/