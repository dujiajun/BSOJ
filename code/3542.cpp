#include<iostream>
using namespace std;
int n,k,a[200005],s[200005],q[200005],len;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)if(a[i]<a[k])q[++q[0]]=a[i];
	q[++q[0]]=a[k];
	for(int i=k;i<=n;i++)if(a[i]>a[k])q[++q[0]]=a[i];
	int l,r,mid;
	for(int i=1;i<=q[0];i++)
	{
		if(q[i]>s[len])s[++len]=q[i];
		l=1,r=len;
		while(l<r)
		{
			mid=(l+r)/2;
			if(s[mid]>=q[i])r=mid;
			else l=mid+1;
		}
		s[r]=q[i];
	}
	cout<<len<<endl;
	return 0;
}