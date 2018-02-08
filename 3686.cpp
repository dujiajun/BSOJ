#include<iostream>
using namespace std;
int n,k,a[400005],c[200005],sum[100005];
long long ans=0;
inline int lowbit(int i){return i&(-i);}
void add(int x){for(int i=x;i<=n*2+1;i+=lowbit(i))c[i]++;}
int ask(int x)
{
	int tmp=0;
	for(int i=x;i>=1;i-=lowbit(i))tmp+=c[i];
	return tmp;
}
int main()
{
	cin>>n>>k;
	add(n+1);sum[0]=n+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=k)a[i]=1;
		else a[i]=-1;
		sum[i]=sum[i-1]+a[i];
		ans=ans+(long long)ask(sum[i]);
		add(sum[i]);
	}
	cout<<ans<<endl;
	return 0;
}