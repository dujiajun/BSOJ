#include<iostream>
using namespace std;
int n,a[200005],f[200005]={0},maxx=0,c=1,l=1,r=1,mid=1;
int main()
{
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		f[i]=a[i];
 	}
 	for(int i=2;i<=n;i++)
 	{
 		l=1,r=c;
 		if(f[c]<a[i]){f[++c]=a[i];continue;}
 		while(l<=r)
 		{
 			mid=(l+r)/2;
 			if(f[mid]<a[i])l=mid+1;
 			else r=mid-1;
 		}
 		f[l]=a[i];
 	}
 	cout<<n-c;
	return 0;
}
