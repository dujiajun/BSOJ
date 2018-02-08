#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int st,ed;}a[20005];
int n,ans,r,l;
inline bool cmp(edge e1,edge e2){return e1.st<e2.st||e1.st==e2.st&&e1.ed<e2.ed;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].st,&a[i].ed);
	sort(a+1,a+n+1,cmp);
	ans=0;r=a[1].ed;l=a[1].st;
	for(int i=2;i<=n;i++)
	{
		if(a[i].st<=r&&a[i].ed>r)r=a[i].ed;
		else if(a[i].st>r)
		{
			ans+=r-l;
			l=a[i].st;r=a[i].ed;
		}
	}
	ans+=r-l;
	cout<<ans<<endl;
	return 0;
}