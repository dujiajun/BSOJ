#include<iostream>
#include<cstring>
using namespace std;
int n,t,q,c[1005][1005]={0};
char ch;
int lowbit(int i){return i&(-i);}
void add(int x,int y,int d){for(int i=x;i<=n;i+=lowbit(i))for(int j=y;j<=n;j+=lowbit(j))c[i][j]+=d;}
int sum(int x,int y)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))
	for(int j=y;j>=1;j-=lowbit(j))ans+=c[i][j];
	return ans%2;
}
void solve()
{
	memset(c,0,sizeof(c));
	cin>>n>>t;
	for(int i=1,x1,x2,y1,y2,x,y;i<=t;i++)
	{
		scanf("\n%c ",&ch);
		if(ch=='C')
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			add(x1,y1,1);add(x2+1,y2+1,1);
			add(x2+1,y1,1);add(x1,y2+1,1);
		}
		if(ch=='Q')
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",sum(x,y));
		}
	}
	printf("\n");
}
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)solve();
	return 0;
}
/*
1
2 10
C 2 1 2 2
Q 2 2
C 2 1 2 1
Q 1 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
Q 1 1
C 1 1 2 1
Q 2 1
*/