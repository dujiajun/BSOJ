#include<iostream>
using namespace std;
struct blc{int p,q,l,r,prt;}a[105]={0};
int n;
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int dfs(int x)
{
	if(x==0)return 1;
	long long w1=dfs(a[x].l)*a[x].p,w2=dfs(a[x].r)*a[x].q;
	long long t=w1*w2/gcd(w1,w2);
	return t/a[x].p+t/a[x].q;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].q>>a[i].l>>a[i].r;
		if(a[i].l)a[a[i].l].prt=i;
		if(a[i].r)a[a[i].r].prt=i;
	}
	for(int i=1;i<=n;i++)
	if(a[i].prt==0)
	{
		cout<<dfs(i)<<endl;
		break;
	}
	return 0;
}
/*
4
3 2 0 4
1 3 0 0
4 4 2 1
2 2 0 0
*/