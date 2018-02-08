#include<iostream>
#include<cstring>
using namespace std;
struct po{int xi,xm,yi,ym;}p[100];
struct nd{int x,y;}a[100];
int n,mc[100]={0},vst[100]={0},map[100][100]={0};
inline bool check(int x,int y)
{
	if(a[x].x>=p[y].xi&&a[x].x<=p[y].xm&&a[x].y>=p[y].yi&&a[x].y<=p[y].ym)return 1;
	return 0;
}
void init_and_build()
{
	memset(map,0,sizeof(map));
	for(int i=1;i<=n;i++)cin>>p[i].xi>>p[i].xm>>p[i].yi>>p[i].ym;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)if(check(i,j))map[i][j]=1;
}
int dfs(int x)
{
	for(int i=1;i<=n;i++)
	if(!vst[i]&&map[x][i])
	{
		vst[i]=1;
		if(mc[i]==-1||dfs(mc[i])){mc[i]=x;return 1;}
	}
	return 0;
}
void match()
{
	int ans=0;
	memset(mc,-1,sizeof(mc));
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		dfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(mc[i]==-1)continue;
		int x=mc[i];
		mc[i]=-1;memset(vst,0,sizeof(vst));
		map[x][i]=0;
		if(!dfs(x))
		{
			ans++;mc[i]=x;
			if(ans>1)cout<<" ";
			cout<<"("<<char(i+'A'-1)<<","<<mc[i]<<")";
		}
		map[x][i]=1;
	}
	if(!ans)cout<<"none";
	cout<<endl<<endl;
}
int main()
{
	int t=0;
	while(1)
	{
		cin>>n;
		if(n==0)break;
		init_and_build();
		cout<<"Heap "<<++t<<endl;
		match();
	}
	return 0;
}
/*
4
6 22 10 20
4 18 6 16
8 20 2 18
10 24 4 8
9 15
19 17
11 7
21 11
2
0 2 0 2
0 2 0 2
1 1
1 1
0
*/