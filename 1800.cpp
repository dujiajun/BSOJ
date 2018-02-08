#include<iostream>
#include<cstring>
using namespace std;
const int dx[15]={2,2,-2,-2,1,1,-1,-1,2,2,-2,-2},dy[15]={-1,1,-1,1,2,-2,2,-2,-2,2,2,-2};
struct node{int x,y,t,k;}q[20005];
int n=100,vst[105][105];
void bfs(int x,int y)
{
	q[1].x=x;q[1].y=y;
	int l=1,r=1,xx,yy,nx,ny;
	vst[x][y]=1;
	while(l<=r)
	{
		xx=q[l].x;yy=q[l].y;
		for(int i=0;i<=11;i++)
		{
			nx=xx+dx[i];ny=yy+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vst[nx][ny])
			{
				r++;
				q[r].x=nx;
				q[r].y=ny;
				q[r].t=q[l].t+1;
				vst[nx][ny]=1;
				if(nx==1&&ny==1)
				{
					cout<<q[r].t<<endl;
					return;
				}
			}
		}
		l++;
	}
}
int main()
{
	int x,y;
	cin>>x>>y;
	bfs(x,y);
	cin>>x>>y;
	memset(vst,0,sizeof(vst));
	memset(q,0,sizeof(q));
	bfs(x,y);
	return 0;
}
/*
12 16
18 10
*/