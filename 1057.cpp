#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[10005],j,minn,pos;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(m--)
	{
		minn=1200000;
		for(int i=n-1;i>=1;i--)if(a[i]<a[i+1]){j=i;break;}
		for(int i=n;i>=j;i--)
		if(a[i]>a[j]&&a[i]<minn){minn=a[i];pos=i;}
		swap(a[pos],a[j]);
		sort(a+j+1,a+n+1);
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}