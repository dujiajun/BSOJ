#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;
struct tree{int l,r;tree(){l=r=-1;}}tree[50];
map<string,int>m;
int n,l[50],P,nd[50][50],mk[50][50],now[50],son[50],opt[50][200];
char buf1[50],buf2[50];
string f[50];
void init()
{
	cin>>n;
 	for(int i=1;i<=n;i++)
  	{
	  	getchar();
   		gets(buf1);
   		gets(buf2);
   		f[i]=buf2;
   		m[(string)buf1]=i;
   		cin>>l[i];
   		for(int j=1;j<=l[i];j++)cin>>nd[i][j];
   		for(int j=1;j<=l[i];j++)cin>>mk[i][j];
  	}
   	cin>>P;
   	for(int i=1;i<=n;i++)scanf("%d",&now[i]);
  	memset(son,-1,sizeof(son));
  	for(int i=1;i<=n;i++)
	{
		int nfa=m[f[i]];
	 	if(son[nfa]==-1)tree[nfa].l=i;
		else tree[son[nfa]].r=i;
	 	son[nfa]=i;
   	}
}
int dp(int r,int p)
{
	if(r==-1)return 0;
 	if(opt[r][p]!=-1)return opt[r][p];
 	int sum=dp(tree[r].r,p);
 	if(now[r])
	{
		for(int i=0;i<=p;i++)
	 	{
		 	int tmp=dp(tree[r].l,i)+dp(tree[r].r,p-i);
	  		if(tmp>sum)sum=tmp;
	 	}
	}
 	int tp=0,tm=0;
 	for(int i=1;i<=l[r];i++)
	{
		if(i>now[r])tp+=nd[r][i],tm+=mk[r][i];
		for(int j=0;j<=p-tp;j++)
		{
			int tmp=dp(tree[r].l, j)+dp(tree[r].r,p-tp-j)+tm;
		 	if(tmp>sum)sum=tmp;
		}
	}
	return opt[r][p]=sum;
}
void solve()
{
	memset(opt,-1,sizeof(opt));
 	for(int i=0;i<200;i++)opt[0][i]=0;
 	cout<<dp(tree[0].l,P);
}
int main()
{
	init();
 	solve();
 	return 0;
}
