#include<iostream>
using namespace std;
int c[200005]={0},n,m;
string s;
int lowbit(int i){return i&(-i);}
int modify(int x,int d){for(int i=x;i<=n;i+=lowbit(i))c[i]+=d;}
int sum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}
int ask(int x,int y){return sum(y)-sum(x-1);}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>s>>x>>y;
		if(s=="Add")modify(x,y);
		if(s=="Sub")modify(x,-y);
		if(s=="Ask")cout<<ask(x,y)<<endl;
	}
	return 0;
}
/*
10 6
Add 2 3
Sub 3 1
Ask 3 7
Add 4 2
Ask 3 6
Sub 1 1
*/