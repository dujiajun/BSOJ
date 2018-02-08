#include<iostream>
using namespace std;
int n,m,a[30005]={0},c[30005]={0};
int find(int x)
{
	if(a[x]==x)return x;
	a[x]=find(a[x]);
	return a[x];
}
void Union(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1!=f2){a[f1]=f2;c[f2]+=c[f1];}
}
void init()
{
	cin>>n>>m;
	int x,y,ans=-0x7f;
	for(int i=1;i<=n;i++){a[i]=i;c[i]=1;}
	for(int i=1;i<=m;i++){cin>>x>>y;Union(x,y);}
	for(int i=1;i<=n;i++)ans=max(ans,c[i]);
	cout<<ans<<endl;
}
int main()
{
	init();
	return 0;
}
/*
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 10
1 2
9 10
8 9
*/