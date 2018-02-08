#include<iostream>
#include<algorithm>
using namespace std;
struct cow{int u,d;}a[30000]={0};
int n,t1=0,t2=0;
inline bool cmp(cow c1,cow c2)
{
	if(c1.u<c1.d&&c2.u>=c2.d)return 1;
	if(c1.u<c1.d&&c2.u<c2.d)return c1.u<c2.u;
	if(c1.u>=c1.d&&c2.u>=c2.d)return c1.d>c2.d;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].u,&a[i].d);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		t1+=a[i].u;
		t2=max(t1,t2)+a[i].d;
	}
	cout<<t2<<endl;
	return 0;
}