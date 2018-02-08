#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
char map[50][50];
int n,m,spots[3][2500][2],cnt[3],minn=301,num_spots=0,mins[3];
void mark(int a,int b,int num)
{
  	if(a<0||b<0||a==n||b==m||map[a][b]!='X')return;
  	map[a][b]='V';
  	spots[num][cnt[num]][0]=a;
  	spots[num][cnt[num]++][1]=b;
  	mark(a-1,b,num);mark(a+1,b,num);
  	mark(a,b-1,num);mark(a,b+1,num);
}
int dist(int a1,int b1,int a2,int b2) 
{return abs(a1-a2)+abs(b1-b2);}
int try_point(int a,int b) 
{
  	if(map[a][b]=='V')return 1000;
  	int i,j,ans=0;
  	for(i=0;i<3;i++)
  	{
    	int minn=101;
    	for(j=0;j<cnt[i];j++)
		{
      		int t=dist(spots[i][j][0],spots[i][j][1],a,b)-1;
      		if(t<minn)minn=t;
    	}
    	ans+=minn;
  	}
  	return ans+1;
}
void init()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)scanf("%s",map[i]);
}
void solve()
{
	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
      		if(map[i][j]=='X')mark(i,j,num_spots++);
  	for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) 
	{
      	int t=try_point(i,j);
      	if(t<minn)minn=t;
    }
  	for(int i=0;i<3;i++) 
  	{
    	mins[i]=101;
    	for(int j=0;j<cnt[i];j++)
      	for(int k=0;k<cnt[(i+1)%3];k++)
	  	{
        	int t=dist(spots[i][j][0],spots[i][j][1],spots[(i+1)%3][k][0],spots[(i+1)%3][k][1])-1;
        	if(t<mins[i])mins[i]=t;
      	}
  	}
	for(int i=0;i<3;i++)
		if(mins[i]+mins[(i+1)%3]<minn)minn=mins[i]+mins[(i+1)%3];
	cout<<minn;
}
int main() 
{
	init();
  	solve();
	return 0;
}