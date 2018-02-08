#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[200000]={0},l,r,t;
int lowbit(int i){return i&(-i);}
void modify(int x){for(int i=x;i<=n;i+=lowbit(i))c[i]++;}
int ask(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))ans+=c[i];
    return ans;
}
int getint()
{
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int ret=0;
	while (c>='0'&&c<='9')
	{
    	ret=ret*10+(c-'0');
    	c=getchar();
    }
	return ret;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		t=getint();
		if(t==1)
		{
			l=getint();r=getint();
			modify(l);modify(r+1);
		}
		if(t==2)
		{
			l=getint();
			printf("%d\n",ask(l)%2);
		}
	}
	return 0;
}
/*
20 10
1 1 10
2 6
2 12
1 5 12
2 6
2 15
1 6 16
1 11 17
2 12
2 6
*/