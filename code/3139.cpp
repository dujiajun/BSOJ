#include<iostream>
#include<algorithm>
using namespace std;
struct nd{int a,g;}a[100005];
int n,stack[100005],tot=0,l=1,r=n,mid;
bool cmp(nd aa,nd bb){return aa.a<bb.a||(aa.a==bb.a&&aa.g>bb.g);}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].g=i-a[i].a;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].g<0)continue;
		stack[tot+1]=0x7fff;
		l=1,r=tot+1;
		while(1)
		{
			if(l==r)break;
			if(l+1==r)
			{
				if(stack[l]>a[i].g)break;
				l++;
				break;
			}
			mid=(l+r)/2;
			if(stack[mid]<=a[i].g)l=mid;
			else r=mid;
		}
		stack[l]=a[i].g;
		if(l>tot)tot++;
	}
	cout<<tot<<endl;
	return 0;
}