#include<iostream>
#include<algorithm>
using namespace std;
struct cow{int l,r;}a[2501];
struct tan{int p,c;}b[2501];
inline bool cmp1(cow x,cow y){return x.r<y.r||x.r==y.r&&x.l<y.l;}
inline bool cmp2(tan x,tan y){return x.p<y.p;}
int vst[2501],n,m,ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
    for(int i=1;i<=m;i++)cin>>b[i].p>>b[i].c;
    sort(a+1,a+n+1,cmp1);
    sort(b+1,b+m+1,cmp2);
    for(int i=1,j;i<=m;i++)
    while(b[i].c)
    {
		for(j=1;j<=n;j++)if(vst[j]==0&&a[j].l<=b[i].p&&b[i].p<=a[j].r)break;
		if(j==n+1)break;
        vst[j]=1;
        b[i].c--;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}