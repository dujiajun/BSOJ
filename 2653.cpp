#include<iostream>
using namespace std;
int c[2000][2000]={0},n,m,w;
int lowbit(int i){return i&(-i);}
int modify(int x,int y,int d)
{
	for(int i=x;i<=n;i+=lowbit(i))
	for(int j=y;j<=n;j+=lowbit(j))c[i][j]+=d;
}
int sum(int x,int y)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
	for(int j=y;j>0;j-=lowbit(j))ans+=c[i][j];
	return ans;
}
int ask(int x1,int y1,int x2,int y2){return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);}
int main()
{
	int x,y,a,l,r,b,t;
	while(scanf("%d",&w))
	{
		if(w==0)cin>>n;
		if(w==3)break;
		if(w==1)
		{
			scanf("%d%d%d",&x,&y,&a);
			modify(x+1,y+1,a);
		}
		if(w==2)
		{
			scanf("%d%d%d%d",&l,&b,&r,&t);
			printf("%d\n",ask(l+1,b+1,r+1,t+1));
		}
	}
	return 0;
}
/*
0 4 
1 1 2 3
2 0 0 2 2 
1 1 2 -1 
2 1 1 2 3 
3
*/