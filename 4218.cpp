#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char st[10005][105],tmp[105][10005];
int Next[10005],n,r;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
void get_next(char *t,int len)
{
	Next[1]=0;int j=0;
	for(int i=2;i<=len;i++)
	{
		while(j>0&&t[j+1]!=t[i])j=Next[j];
		if(t[j+1]==t[i])j++;
		Next[i]=j;
	}
}
int main()
{
	cin>>n>>r;int x1=1,ll=1,x2=1,ans=1;
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=r;j++){st[i][j]=getchar();tmp[j][i]=st[i][j];}
		memset(Next,0,sizeof(Next));
		get_next(st[i],r);
		x1=r-Next[r];
		ans=ans*x1/gcd(ans,x1);
	}
	for(int i=1;i<=r;i++)
	{
		memset(Next,0,sizeof(Next));
		get_next(tmp[i],n);
		x2=n-Next[n];
		ll=ll*x2/gcd(ll,x2);
	}
	ans=min(ans,r);ll=min(ll,n);
	cout<<ans*ll<<endl;
	return 0;
}
/*
2 5
ABABA
BABAB
*/