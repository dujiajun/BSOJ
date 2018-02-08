#include<iostream>
#include<algorithm>
using namespace std;
struct node{int s;double ed;}g[100005];
int n;
long long c,l,v[100005],q[100005]={0},t[100005]={0},tot[100005]={0},ans=0;
inline int lowbit(int i){return i&(-i);}
void add(int x,int d){for(int i=x;i<=n;i+=lowbit(i))t[i]+=d;}
inline bool cmp(node i,node j){return i.ed<j.ed||i.ed==j.ed&&i.s<j.s;}
long long ask(int x)
{
	long long tmp=0;
	for(int i=x;i>=1;i-=lowbit(i))tmp+=t[i];
	return tmp;
}
int main()
{
	cin>>n>>l>>c;
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++)
	{
		q[i]=l*v[i]/v[n];
		g[i].s=i;
		g[i].ed=(l*c*v[i])%(c*v[n]);
	}
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=n;i++)tot[i]=tot[i-1]+q[i];
	for(int i=1;i<=n;i++)ans+=q[i]*(i-1)-tot[i-1]-(i-1); 
	for(int i=1;i<=n;i++)
	{
		ans+=ask(g[i].s);
		add(g[i].s,1);
	}
	cout<<ans<<endl;
	return 0;
} 