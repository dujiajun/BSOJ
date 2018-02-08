#include<iostream>
using namespace std;
struct cir{int x,y,r;double v;}a[1200];
double ans=0;
int n,map[1200][1200]={0},xt,yt,st,ed,vst[1050]={0},prt[1050]={0};
int dis(int ax,int ay,int bx,int by){return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);}
void dfs(int x,double v)
{
	a[x].v=v;
	for(int i=1;i<=n;i++)
	if(map[x][i]&&i!=prt[x]&&!vst[i])
	{
		prt[i]=x;vst[i]=1;
		dfs(i,v*a[x].r/a[i].r);
	}
}
int main()
{
	//freopen("baler.in","r",stdin);
	//freopen("baler.out","w",stdout);
	cin>>n>>xt>>yt;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].r;
		if(a[i].x==0&&a[i].y==0)st=i;
		if(a[i].x==xt&&a[i].y==yt)ed=i;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(dis(a[i].x,a[i].y,a[j].x,a[j].y)==(a[i].r+a[j].r)*(a[i].r+a[j].r))map[i][j]=map[j][i]=1;
	dfs(st,10000);
	for(int i=ed;i;i=prt[i])ans+=a[i].v;
	cout<<(int)ans<<endl;
	return 0;
}
/*
4 32 54
0 0 10
0 30 20
32 54 20
-40 30 20
*/