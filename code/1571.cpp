#include<iostream>
#include<cstring>
using namespace std;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct queue{int x,y;}q[100005]={0};
int n,a[210][210]={0},minn,maxx,vst[210][210]={0},h[500]={0},b[500]={0};
int bfs(int down,int up)
{
	int x=1,y=1,nx,ny,l=1,r=1;
	memset(vst,0,sizeof(vst));
	if(a[1][1]>up||a[1][1]<down)return 0;
	q[l].x=1;q[l].y=1;
	while(l<=r)
	{
		x=q[l].x;y=q[l].y;
		for(int i=0;i<=3;i++)
		{
			nx=x+dx[i];ny=y+dy[i];
			if(!vst[nx][ny]&&nx>=1&&nx<=n&&ny>=1&&ny<=n&&a[nx][ny]>=down&&a[nx][ny]<=up)
			{
				vst[nx][ny]=1;
				r++;
				q[r].x=nx;
				q[r].y=ny;
				if(nx==n&&ny==n)return 1;
			}
		}
		l++;
	}
	return 0;
}
bool check(int x)
{
	for(int i=1;i<=b[0];i++)if(bfs(b[i],b[i]+x))return 1;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][j];
		h[a[i][j]]=1;
		minn=min(minn,a[i][j]);
		maxx=max(maxx,a[i][j]);
	}
	for(int i=0;i<=maxx;i++)if(h[i])b[++b[0]]=i;
	int l=0,r=maxx-minn,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}
/*
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 2 4
4 3 0 3 1
*/