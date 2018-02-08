#include<iostream>
using namespace std;
char a[1001][1001];
struct queue{int x,y;}q[1000001];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},n,m,co[1000001]={0},bl[1000001],vst[1001][1001]={0};
inline int num(int a,int b){return (a-1)*n+b;}
void bfs(int x,int y)
{  
   	int l=1,r=1,fa=num(x,y),nx,ny;
   	q[1].x=x;q[1].y=y;vst[x][y]=1;
   	while(l<=r)
   	{
	   	for(int i=0;i<=3;i++)
		{  
			nx=q[l].x+dx[i];ny=q[l].y+dy[i];
         	if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vst[nx][ny]&&a[nx][ny]!=a[q[l].x][q[l].y])
         	{  
			 	vst[nx][ny]=1;
            	q[++r].x=nx;q[r].y=ny;
            	bl[num(nx,ny)]=fa;
         	}
      	}
		l++;
 	}
   	co[fa]=r;
}
int main()
{   
    cin>>n>>m;getchar();
    for(int i=1;i<=n;i++)
    { 
		for(int j=1;j<=n;j++)
		{
			char c=getchar();
			while(c!='0'&&c!='1')c=getchar();
			a[i][j]=c;
		}
    }
    for(int i=1;i<=n*n;i++)bl[i]=i;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)if(!vst[i][j])bfs(i,j);
    for(int i=1,x,y;i<=m;i++)
    {  
		scanf("%d%d",&x,&y);
        printf("%d\n",co[bl[num(x,y)]]); 
    }
    return 0; 
}