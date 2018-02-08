#include<iostream>
using namespace std;
const int MAXN=100005;
struct edge{int next,to;}a[MAXN*2];
int cnt=0,h[MAXN],q[MAXN],day[MAXN],n,m,st,vst[MAXN]={0},ans=1;
void Add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void bfs()
{
	int head=0,tail=1,x;
	vst[st]=1;day[1]=1;q[1]=st;
	while(head<tail)
	{
		x=q[(++head)%MAXN];
		for(int i=h[x];i;i=a[i].next)
		{
			int to=a[i].to;
			if(!vst[to])
			{
				vst[to]=1;
				q[(++tail)%MAXN]=to;
				day[tail]=day[head]+1;
				ans=max(day[tail],ans);
			}
		}
	}
	
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);Add(y,x);
	}
	cin>>st;
	bfs();
	cout<<ans<<endl;
	return 0;
}
/*
4 4
1 2
2 3
3 4
2 4
1
*/
