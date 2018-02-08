#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff/2;
int n,s,map[302][302],dis=0,st,ed,ans=INF;
void init()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(i==j)map[i][j]=0;else map[i][j]=INF;
    for(int i=1,x,y,z;i<=n-1;i++)
    {
       cin>>x>>y>>z;
       map[x][y]=map[y][x]=z;
    }
}
void Floyd()
{
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
       int t=map[i][k]+map[k][j];
       map[i][j]=min(t,map[i][j]);
       if(map[i][j]!=INF&&dis<map[i][j])
       {
          dis=map[i][j];
          st=i;ed=j;
       }
    }
}
bool check(int x,int y)
{
    if(map[st][x]+map[x][ed]!=dis)return 0;
    if(map[st][y]+map[y][ed]!=dis)return 0;
    if(map[x][y]>s)return 0;
    return 1;
}

int main()
{
    init();
    Floyd();
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(check(i,j))
    {
        int x=min(map[st][i],map[st][j]);
        int y=min(map[i][ed],map[j][ed]);
        ans=min(ans,max(x,y));     
    }
    cout<<ans<<endl;
    return 0;
}