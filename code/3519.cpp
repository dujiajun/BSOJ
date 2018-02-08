#include<iostream>
#include<algorithm>
using namespace std;
struct node{int r,d,id;}a[100005];
int n,q[100005],tot,num[100005];
inline bool cmp(node n1,node n2){return n1.d>n2.d||n1.d==n2.d&&n1.r>n2.r;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].d,&a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=tot+1,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			if(q[mid]<=a[i].r)r=mid;
			else l=mid+1;
		}
		q[r]=a[i].r;
		num[a[i].id]=r;
		if(r==tot+1)tot++;
	}
	for(int i=1;i<=n;i++)printf("%d\n",num[i]);
	return 0;
}