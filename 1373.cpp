#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int a,b;}a[20005];
int n,stk[20005],tot,maxx;
inline bool cmp(edge e1,edge e2){return e1.a<e2.a||e1.a==e2.a&&e1.b<e2.b;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].b>stk[tot])stk[++tot]=a[i].b;
		else
		{
			int l=1,r=tot,mid;
			while(l<r)
			{
				mid=(l+r)/2;
				if(stk[mid]>=a[i].b)r=mid;
				else l=mid+1;
			}
			stk[r]=a[i].b;
		}
		maxx=max(maxx,tot);
	}
	cout<<maxx<<endl;
	return 0;
}
/*
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2
*/