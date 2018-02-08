#include<iostream>
#include<cstring>
using namespace std;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m,t=0,in[16]={0},st[70000]={-1},a[70][70]={-1},map[70][70]={0};
char mz[70][70];
int chg(char c)
{
	switch(c)
	{
		case '^':return 0;
		case 'v':return 1;
		case '<':return 2;
		case '>':return 3;
		default:return -1;
	}
}
int top(int k,int sta)
{
	if(st[sta]!=-1)return st[sta];
	if(k==t)return 1;
	int ret=0;
	for(int i=0;i<t;i++)
	if(in[i]==0)
	{
		in[i]=-1;
		for(int j=0;j<t;j++)if(map[i][j])in[j]--;
		ret+=top(k+1,sta+(1<<i));
		in[i]=0;
		for(int j=0;j<t;j++)if(map[i][j])in[j]++;
	}
	return st[sta]=ret;
}
int main()
{
	cin>>n>>m;
	memset(a,-1,sizeof(a));
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)cin>>mz[i][j];
	for(int i=0,d;i<n;i++)
	for(int j=0;j<m;j++)
	{
		d=chg(mz[i][j]);
		if(d<0)continue;
		if(a[i][j]==-1)a[i][j]=t++;
		for(int k=1,x,y;;k++)
		{
			x=i+k*dx[d];y=j+k*dy[d];
			if(x<0||x>=n||y<0||y>=m||mz[x][y]=='#')break;
			if(chg(mz[x][y])>=0)
			{
				if(a[x][y]==-1)a[x][y]=t++;
				map[a[x][y]][a[i][j]]=1;
			}
		}
	}
	for(int i=0;i<t;i++)
	for(int j=0;j<t;j++)if(map[i][j])in[j]++;
	memset(st,-1,sizeof(st));
	int ans=top(0,0);
	if(ans>0)cout<<ans<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}
/*
2 2 
>^ 
#^
*/