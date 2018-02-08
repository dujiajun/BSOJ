#include<iostream>
#include<cstring>
using namespace std;
struct Node{int x,y;}ax[1010],ay[1010],ah[1010],al[1010];
const int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
int n,nx,ny,nh,nl,rest,map[50][50]={0},c1[50][50]={0},p,c2[50][50]={0},my[1010]={0},f[1010][5]={0},vst[1010]={0};
void build() 
{  
   	nx=ny=0;
   	for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(!map[i][j])
    {  
		if((i+j)%2){nx++;ax[nx].x=i;ax[nx].y=j;c1[i][j]=nx;}
        else {ny++;ay[ny].x=i;ay[ny].y=j;c2[i][j]=ny;}
    }
   	for(int x=1;x<=nx;x++)
   	{  
	   	int i=ax[x].x,j=ax[x].y;
      	for(int k=0;k<=3;k++)
      	{  
		  	int tx=i+dx[k],ty=j+dy[k];
         	if(c2[tx][ty])f[x][++f[x][0]]=c2[tx][ty];
      	}
   	}
}
int dfs(int x)
{  
   	for(int i=1;i<=f[x][0];i++)
   	{  
	   	int y=f[x][i];
      	if(!vst[y])
      	{  
		  	vst[y]=1;
         	if(!my[y]||dfs(my[y])){my[y]=x;return 1;}
      	}
   	}
   return 0;
}
void out()
{  
   	cout<<"Yes"<<endl;
	nh=nl=0;
   	for(int j=1;j<=ny;j++)
   	{  
	   	int i=my[j];
      	if(ax[i].x==ay[j].x-1){nh++;ah[nh]=ax[i];}
      	if(ax[i].x==ay[j].x+1){nh++;ah[nh]=ay[j];}
      	if(ax[i].y==ay[j].y-1){nl++;al[nl]=ax[i];}
      	if(ax[i].y==ay[j].y+1){nl++;al[nl]=ay[j];}
   	}
   	cout<<nh<<endl;
   	for(int i=1;i<=nh;i++)cout<<ah[i].x<<" "<<ah[i].y<<endl;
   	cout<<nl<<endl;
   	for(int i=1;i<=nl;i++)cout<<al[i].x<<" "<<al[i].y<<endl;
}
void solve()
{  
   	for(int i=1;i<=nx;i++)  
   	{  
	   	memset(vst,0,sizeof(vst));
      	if(dfs(i))rest-=2;
   	}
   	if(rest)cout<<"No"<<endl; 
	else out();
}
int main()
{  
   	cin>>n>>p;
   	rest=n*n-p;
   	if(rest%2){cout<<"No"<<endl;return 0;}
   	for(int i=1,x,y;i<=p;i++){cin>>x>>y;map[x][y]=1;}
   	build();
	solve();
   	return 0;
}