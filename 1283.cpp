#include<iostream>
#include<cstring> 
#include<cstdio>
using namespace std;
int dx[5]={0,1,2,2,1};
int dy[5]={0,2,1,-1,-2};
long long n,m,map[55][55]={0},sol;
bool v[55][55]={false};
struct node{int x,y,data,val;}f[2555];
void Doit1()
{
     cin>>n>>m;
     f[1].x=1,f[1].y=1;f[1].data=0;
     int head=1,tail=1,i,result=0,j=0;
     while(head<=tail)
     {
       int x2,y2;               
       for(i=1;i<=4;i++)
       {
         x2=f[head].x+dx[i];y2=f[head].y+dy[i];
         if(x2>0&&y2>0&&x2<=n&&y2<=m&&v[x2][y2]==false)
           {v[x2][y2]=true;tail++;f[tail].x=x2;f[tail].y=y2;f[tail].data=head;}
         if(f[tail].x==n&&f[tail].y==m){j=tail;break;}
       }
       head++;
     }
     
     i=0;int a[2505];
     if(j==0)cout<<"no";
     while(j!=0)
     {
       a[++i]=j;
       j=f[j].data;
     }
     for(j=i;j>0;j--)
     {
       cout<<"("<<f[a[j]].x<<","<<f[a[j]].y<<")";
       if(j!=1)cout<<"->";
     }
}
void Doit2()
{
     int sx,sy,ex,ey,i,j,k;
     long long a[5];
     cin>>n>>m>>sx>>sy>>ex>>ey;//x--lie''y--hang
     map[sy][sx]=1;
     for(i=sx+1;i<=ex;i++)
       for(j=1;j<=m;j++)
       {
         memset(a,0,sizeof(a));
         for(k=1;k<=4;k++)
           if(i-dx[k]>0&&j-dy[k]>0&&i-dx[k]<=n&&j-dy[k]<=m)a[k]=map[j-dy[k]][i-dx[k]];
         map[j][i]=a[1]+a[2]+a[3]+a[4];
       }
    cout<<map[ey][ex];
}   

int main()
{
    cin>>sol;
    if(sol==1)Doit1();
    else Doit2();
    getchar();getchar();
    return 0;
}
