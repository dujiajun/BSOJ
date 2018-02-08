#include<iostream>
using namespace std;
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
int m,n,b[205][205]={0};
char a[205][205];
struct node{int x,y,s;}f[40000],t,sta;
bool ok(int x,int y)
{
	if(x>0&&x<=n&&y>0&&y<=m&&!b[x][y])
	if(a[x][y]=='.'||a[x][y]=='r'||a[x][y]=='x')return true;
	return false;
}
void bfs()
{
	int head=1,tail=1,x,y;
	f[1].x=sta.x;f[1].y=sta.y;b[sta.x][sta.y]=1;f[1].s=0;
	while(head<=tail)
	{
		t.x=f[head].x;t.y=f[head].y;
		if(a[t.x][t.y]=='x')
		{
			a[t.x][t.y]='.';
			tail++;
			f[tail].x=t.x;f[tail].y=t.y;f[tail].s=f[head].s+1;
			head++;
			continue;
		}
		for(int i=0;i<4;i++)
		{
			x=t.x+dx[i];y=t.y+dy[i];
			if(ok(x,y))
			{
				b[x][y]=1;
				tail++;
				f[tail].x=x;f[tail].y=y;f[tail].s=f[head].s+1;
				if(a[x][y]=='r'){cout<<f[tail].s<<endl;return;}
			}
		}
		head++;
	}
	cout<<"Poor ANGEL."<<endl;
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>a[i][j]; 
		if(a[i][j]=='a'){sta.x=i;sta.y=j;a[i][j]='.';}
	}
}

int main()
{
	init();
	bfs();
	return 0;
}
