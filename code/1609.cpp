#include<iostream>
using namespace std;
char a[255][255];
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1},w=0,s=0,rw=0,rs=0,R,C;
struct nc{int x,y;}c[65500];
int b[255][255]={0};
void bfs()
{
	int h=-1,t=0;
	while(h<=t)
	{
		for(int i=0;i<4;i++)
		{
			int x=c[h].x+dx[i],y=c[h].y+dy[i];
			if(x>0&&y>0&&x<=R&&y<=C&&b[x][y]==0)
			{
				t++;
				c[t].x=x;c[t].y=y;
				if(a[x][y]=='v')w++;
				if(a[x][y]=='o')s++;
				b[x][y]=1;
			}
		}
		h++;
	}
}
void init()
{
	cin>>R>>C;
	for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
		cin>>a[i][j];
		if(a[i][j]=='#')b[i][j]=1;
	}
	for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
		s=w=0;
		if(b[i][j]==0)
		{
			if(a[i][j]=='o')s++;
			if(a[i][j]=='v')w++;
			b[i][j]=1;
			c[0].x=i;c[0].y=j;
			bfs();
			if(s>w)rs+=s;
			else rw+=w;
		}
	}
}
int main()
{
	init();
	cout<<rs<<" "<<rw<<endl;
	return 0;
}