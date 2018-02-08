#include<iostream>
#include<cstring> 
using namespace std;
struct Tree
{int l,r,v;}t[310]={0};
int f[310][210]={0},d[310]={0},n,m;
void init()
{   
	cin>>n>>m;
	for(int i=1,x,y;i<=n;i++)
	{   
		cin>>x>>y;
	    t[i].v=y;
		if(d[x]==0)t[x].l=i;else t[d[x]].r=i;
		d[x]=i;
	}
}
int solve(int x,int y)
{
	if(f[x][y]>0)return f[x][y];
	if(x==0||y==0)return 0;
	f[x][y]=solve(t[x].r,y);
	for(int k=1;k<=y;k++)
        f[x][y]=max(f[x][y],solve(t[x].l,k-1)+solve(t[x].r,y-k)+t[x].v);
    return f[x][y];
}
int main()
{
    init();
    cout<<solve(t[0].l,m)<<endl;
    return 0;
}
/*
7 4
2 2
0 1
0 4
2 1
7 1
7 6
2 2
*/