#include<iostream>
#include<algorithm>
using namespace std;

struct lt{int s,e;}l[5005];
bool cmp(lt x,lt y){return x.s<y.s;}
int main()
{
	int n,maxx=0,minn=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i].s>>l[i].e;
	sort(l+1,l+n+1,cmp);
	int x=l[1].s,y=l[1].e;
	minn=y-x;
	for(int i=1;i<=n;i++)
	{
		if(l[i].s<=y&&l[i].e>y)y=l[i].e;
		if(l[i].s>y)
		{
			minn=max(minn,y-x);
			maxx=max(maxx,l[i].s-y);
			x=l[i].s;y=l[i].e;
		}
	}
	cout<<minn<<" "<<maxx;
	return 0;
}
