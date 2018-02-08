#include<iostream>
#include<cstring>
using namespace std;
struct que{int x,y,g;}q[1000];
int n,a[10][10]={0},c[10]={0},tmp[10][10][7]={0},cl[10][10]={0};
bool check()
{
	for(int i=0;i<5;i++)
	for(int j=0;j<7;j++)if(a[i][j])return 0;
	return 1;    
}
void xiao()
{
	for(int i=0;i<5;i++)
	{
		int po=0;
		memset(c,0,sizeof(c));
		for(int j=0;j<7;j++)if(a[i][j]!=0)c[po++]=a[i][j];				
		for(int j=0;j<7;j++)a[i][j]=c[j];			
	}
	bool bj=0;memset(cl,0,sizeof(cl));
	for(int i=0;i<5;i++)
	for(int j=0;j<7;j++)
	if(a[i][j])
	{
		if(i<3&&a[i+1][j]==a[i][j]&&a[i+2][j]==a[i][j]){cl[i][j]=cl[i+1][j]=cl[i+2][j]=1;bj=1;}
		if(j<5&&a[i][j+1]==a[i][j]&&a[i][j+2]==a[i][j]){cl[i][j]=cl[i][j+1]=cl[i][j+2]=1;bj=1;}
	}
	if(bj==0)return;
	for(int i=0;i<5;i++)
	for(int j=0;j<7;j++)if(cl[i][j])a[i][j]=0;
	xiao();
}
void dfs(int dp)
{
	if(dp==n+1)
	{
		if(check()){for(int i=1;i<=n;i++)cout<<q[i].x<<" "<<q[i].y<<" "<<q[i].g<<endl;exit(0);}
		return;
	}
	for(int i=0;i<5;i++)
	for(int j=0;j<7;j++)
	if(a[i][j])
	{
	  	if(i+1<=4)
		{
   	        memcpy(tmp[dp],a,sizeof(a));
			swap(a[i][j],a[i+1][j]);
			q[dp].x=i;q[dp].y=j;q[dp].g=1;
			xiao();
			dfs(dp+1);
			memcpy(a,tmp[dp],sizeof(a));
		}
		if(i-1>=0&&a[i-1][j]==0)
		{
   	        memcpy(tmp[dp],a,sizeof(a));
			swap(a[i][j],a[i-1][j]);
			q[dp].x=i;q[dp].y=j;q[dp].g=-1;
			xiao();
			dfs(dp+1);
			memcpy(a,tmp[dp],sizeof(a));
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0,x;i<5;i++)
	{
		int tt=-1;
		while(1)
		{
			cin>>x;
			if(x==0)break;
			a[i][++tt]=x;
		}
	}	
	dfs(1);	
	cout<<-1<<endl;
	return 0;
}
/*
3
1 0
2 1 0
2 3 4 0
3 1 0
2 4 3 4 0
*/
