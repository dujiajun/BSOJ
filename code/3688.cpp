#include<iostream>
#include<cstring>
using namespace std;
struct line{int x1,x2,y1,y2,k;}l[300];
struct edge{int to,next;}a[90000];
int n,match[300],ans,cnt,h[300];
bool vst[300],map[300][300];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
int dfs(int x)
{
	int to;
	for(int i=h[x];i;i=a[i].next)
	{
		to=a[i].to;
		if(!vst[to])
		{
			vst[to]=1;
			if(!match[to]||(match[to]&&dfs(match[to]))){match[to]=x;return 1;}
		}
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i].x1>>l[i].y1>>l[i].x2>>l[i].y2;
		if(l[i].x1>l[i].x2)swap(l[i].x1,l[i].x2);
		if(l[i].y1>l[i].y2)swap(l[i].y1,l[i].y2);
		if(l[i].x1==l[i].x2)l[i].k=1;//竖直 
		if(l[i].y1==l[i].y2)l[i].k=2;//水平 
	}
	for(int i=1,p,q;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j&&!map[i][j])
	{
		if(l[i].k==l[j].k)continue;
		p=l[i].k==1?i:j;q=l[j].k==2?j:i;
		if(l[p].k==1&&l[q].k==2)
		if(l[p].x1>=l[q].x1&&l[p].x1<=l[q].x2&&l[p].y1<=l[q].y1&&l[p].y2>=l[q].y2)
		{
			add(p,q);
			map[p][q]=map[q][p]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		if(dfs(i))ans++;
	}
	cout<<n-ans<<endl;
	return 0;
}