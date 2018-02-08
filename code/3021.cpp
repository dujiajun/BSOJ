#include<iostream>
#include<algorithm>
using namespace std;
int n,f[100005],s[100005];
long long ans=0;
struct tree{int s,t,d;}tr[100005];
bool cmp(const tree &t1,const tree &t2){return t1.d<t2.d;}
int getf(int x)
{
	if(f[x]==x)return x;
	f[x]=getf(f[x]);
	return f[x];
}
void init()
{
	cin>>n;
	for(int i=1;i<n;i++)cin>>tr[i].s>>tr[i].t>>tr[i].d;
}
void solve()
{
	sort(tr+1,tr+n,cmp);
	for(int i=1;i<=n;i++){f[i]=i;s[i]=1;}
	for(int i=1;i<n;i++)
	{
		int f1=getf(tr[i].s),f2=getf(tr[i].t);
		ans+=((long long)s[f1]*s[f2]-1)*(tr[i].d+1)+tr[i].d;
		f[f1]=f2;
		s[f2]+=s[f1];
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}