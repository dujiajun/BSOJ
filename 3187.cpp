#include<iostream>
#include<algorithm>
using namespace std;
struct per{int s,w,b;}a[300000]={0},w[100005]={0},l[100005]={0};
int n,r,q;
bool cmp(per b,per c){return (b.s>c.s)||(b.s==c.s&&b.b<c.b);}
int main()
{
	cin>>n>>r>>q;
	for(int i=1;i<=n*2;i++)
	{
		scanf("%d",&a[i].s);
		a[i].b=i;
	}
	for(int i=1;i<=n*2;i++)scanf("%d",&a[i].w);
	sort(a+1,a+n*2+1,cmp);
	for(int i=1;i<=r;i++)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i*2].w>a[i*2-1].w)
			{
				a[i*2].s++;
				w[++cnt]=a[i*2];
				l[cnt]=a[i*2-1];
			}
			else 
			{
				a[i*2-1].s++;
				w[++cnt]=a[i*2-1];
				l[cnt]=a[i*2];
			}
		}
		int ww=1,ll=1;cnt=0;
		while(ww<=n&&ll<=n)
		{
			if(cmp(w[ww],l[ll]))a[++cnt]=w[ww++];
			else a[++cnt]=l[ll++];
		}
		while(ww<=n)a[++cnt]=w[ww++];
		while(ll<=n)a[++cnt]=l[ll++];
	}
	//sort(a+1,a+n*2+1,cmp);
	cout<<a[q].b;
	return 0;
}