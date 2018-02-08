#include<iostream>
#include<cstring>
using namespace std;
int n;
int x[10][10],y[10][10],g[4][4][10];
int ans[10][10]={0};
void dfs(int x1,int y1)
{
	int nx,ny;
	if(!y1)
	{
		for(int i=1;i<=9;i++)
		{for(int j=1;j<=9;j++)cout<<ans[i][j];cout<<endl;}
		return ;
	}
	if(x1>=2){nx=x1-1;ny=y1;}
	else {nx=9,ny=y1-1;}
	if(ans[x1][y1]){dfs(nx,ny);return;}
	for(int i=1;i<=9;i++)
	{
		if(!x[x1][i]&&!y[y1][i]&&!g[(x1+2)/3][(y1+2)/3][i])
		{
			x[x1][i]=1;y[y1][i]=1;g[(x1+2)/3][(y1+2)/3][i]=1;
			ans[x1][y1]=i;
			dfs(nx,ny);
			x[x1][i]=0;y[y1][i]=0;g[(x1+2)/3][(y1+2)/3][i]=0;
			ans[x1][y1]=0;
		}
	}
}
void init()
{
	char tmp;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			cin>>tmp;
			if(tmp!='?')
			{
				ans[i][j]=tmp-'0';
				x[i][ans[i][j]]=1;
				y[j][ans[i][j]]=1;
				g[(i+2)/3][(j+2)/3][ans[i][j]]=1;
			}
		}
}
int main()
{
	init();
	dfs(9,9);
	return 0;
}