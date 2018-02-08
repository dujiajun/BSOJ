#include<iostream>
#include<algorithm>
using namespace std;
const int MOD=1000000009;
struct node{int sum,id;}s[1000005];
int n,b[1000005];
long long ans,cnt,c[1000005];
inline bool cmp(const node &n1,const node &n2){return n1.sum<n2.sum||n1.sum==n2.sum&&n1.id<n2.id;}
inline int lowbit(const int &i){return i&(-i);}
void Modify(int x,int d){for(int i=x;i<=n;i+=lowbit(i))c[i]=(c[i]+d)%MOD;}
long long Ask(int x)
{
	long long tmp=0;
	for(int i=x;i;i-=lowbit(i))tmp=(tmp+c[i])%MOD;
	return tmp;
}
int main()
{
	cin>>n;long long a;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		s[i].sum=(s[i-1].sum+a)%MOD;
		s[i].id=i;
	}
	s[n+1].sum=0;s[n+1].id=n+1;
	sort(s+1,s+n+2,cmp);
	for(int i=1,j=0;i<=n+1;i++)
	{
		if(i==1||s[i].sum!=s[i-1].sum)j++;
		b[s[i].id]=j;
	}
	Modify(b[n+1],1);
	for(int i=1;i<=n;i++)
	{
		ans=Ask(b[i]);
		Modify(b[i],ans);
	}
	cout<<ans<<endl;
	return 0;
}