#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MOD=99999997;
int n,r[100005],ans,c[100005];
struct node{int v,pos;}a[100005],b[100005];
inline int lowbit(const int &i){return i&(-i);}
void add(int x,int d){for(int i=x;i<=n;i+=lowbit(i))c[i]+=d;}
int ask(int x)
{
	int tmp=0;
	for(int i=x;i>=1;i-=lowbit(i))tmp+=c[i];
	return tmp;
}
inline bool cmp(const node &x,const node &y){return x.v<y.v;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){scanf("%d",&a[i].v);a[i].pos=i;}
	for(int i=1;i<=n;i++){scanf("%d",&b[i].v);b[i].pos=i;}
	sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)r[a[i].pos]=b[i].pos;
	for(int i=n;i>=1;i--)
	{
		ans=(ans+ask(r[i]))%MOD;
		add(r[i],1);
	}
	cout<<ans<<endl;
	return 0;
}