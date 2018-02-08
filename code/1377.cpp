#include<iostream>
#include<cstring>
using namespace std;
int n,c[100001]={0};
int lowbit(int i){return i&(-i);}
void add(int x,int d){for(int i=x;i<=n;i+=lowbit(i))c[i]+=d;}
int sum(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))ans+=c[i];
	return ans;
}
void solve()
{
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,1);add(y+1,-1);
	}
	for(int i=1;i<=n;i++)printf("%d ",sum(i));
	printf("\n");
}
int main()
{
	while(scanf("%d",&n))
	{
		if(n==0)break;
		solve();
		memset(c,0,sizeof(c));
	}
	return 0;
}