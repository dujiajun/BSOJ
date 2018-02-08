#include<iostream>
#include<algorithm>
using namespace std;
struct node{int sum,id;}s[1000005];
int n,m,b[1000005];
long long ans,cnt,c[1000005],sum[1000005];
inline bool cmp(const node &n1,const node &n2){return n1.sum<n2.sum;}
inline int lowbit(const int i){return i&(-i);}
void Modify(int x,int d){for(int i=x;i<=n;i+=lowbit(i))c[i]=c[i]+d;}
long long Ask(int x)
{
	long long tmp=0;
	for(int i=x;i>=1;i-=lowbit(i))tmp=tmp+c[i];
	return tmp;
}
int main()
{
	cin>>n>>m;long long a;
	n++;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		sum[i]=sum[i-1]+a;
		s[i].sum=sum[i]-(i-1)*m;
		s[i].id=i;
	}
	s[1].sum=0;s[1].id=1;
	sort(s+1,s+n+1,cmp);
	b[s[1].id]=1;
	for(int i=2;i<=n;i++)
	{
		if(s[i].sum==s[i-1].sum)b[s[i].id]=b[s[i-1].id];
		else b[s[i].id]=i;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=Ask(b[i]-1);
		Modify(b[i],1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 3
3 7 2 4
*/