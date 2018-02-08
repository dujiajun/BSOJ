#include<iostream>
using namespace std;
int dx[4]={1,2,2,1},dy[4]={-2,-1,1,2},a[105][1005],m,n;
struct node{int x,y,c;}q[1001];
 void bfs()
{
	int h=1,r=1,x,y;
	q[1].x=0;q[1].y=0;q[1].c=0;a[0][0]=1;
	while(h<=r)
	{
		for(int i=0;i<4;i++)
		{
			x=q[h].x+dx[i];y=q[h].y+dy[i];
			if(x>0&&y>0&&!a[x][y]&&x<=n&&y<=m)
			{
				r++;q[r].x=x;q[r].y=y;q[r].c=q[h].c+1;a[x][y]=1;
			}
			if(q[r].x==n&&q[r].y==m){cout<<q[r].c<<endl;return;}
		}
		h++;
	}
}
int main()
{
	cin>>n>>m;
	bfs();
	return 0;
}