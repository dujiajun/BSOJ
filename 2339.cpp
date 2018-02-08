#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct nd{int x,y;}a[105];
int bl[105]={0},g[105][105]={0},vst[105],bk[105],n,t=0;
bool cmp(nd a,nd b){return a.x<b.x;}
bool dfs(int i)
{  
	for(int j=1;j<=n;j++)
    if(g[i][j]==0&&!vst[j])
    {  
	 	vst[j]=1;
        if(bl[j]==0||dfs(bl[j])){bl[j]=i;return true;}
    }
   	return false;
}
int xiong()
{  
	int ans=0,bj=0;
   	for(int i=1;i<=n;i++)
   	{  
	   	memset(vst,0,sizeof(vst));
      	if(dfs(i))ans++;
   	}
   	if(ans!=n)return 0;
   	memcpy(bk,bl,sizeof(bl));
   	for(int i=1;i<=n;i++)
   	{  
	   	g[bk[i]][i]=1;
      	bl[i]=0;
      	memset(vst,0,sizeof(vst));
      	if(!dfs(bk[i])){a[++t].x=bk[i];a[t].y=i;bj=1;}
      	memcpy(bl,bk,sizeof(bk));
      	g[bk[i]][i]=0;
   	}
   	if(!bj)return 0;
	else return 1;
}
int main()
{  
	int x,y;
   	cin>>n;
   	while(cin>>x>>y)
   	{  
	   	if(x==0&&y==0)break;
      	g[x][y]=1;
   	}
   	if(xiong())
   	{
   		sort(a+1,a+t+1,cmp);
        for(int i=1;i<=t;i++)cout<<a[i].x<<" "<<a[i].y<<endl;
   	}
    else cout<<"none"<<endl;
    return 0;
}
