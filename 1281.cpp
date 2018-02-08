#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int n,map[11][11]={0},vst[105]={0},b[205]={0};
bool check(int x)
{
    if(x==1||x==2)return false;
    for(int i=2;i<=sqrt(x);i++)if(x%i==0)return false;
    return true;
}
bool check(int x,int y,int num)
{
    if(x==1)
        return b[num+map[x][y-1]];
    if(y==1)
        return b[num+map[x-1][y]];
    return b[num+map[x][y-1]]&&b[num+map[x-1][y]];
}
void out()
{
	for(int l=1;l<=n;l++)
    {
        for(int r=1;r<=n;r++)cout<<map[l][r]<<" ";
        cout<<endl;
    }
        exit(0);
}
void dfs(int x,int y)
{
    if(x==n+1||y==n+1)out();
    if(map[x][y])
    {
        if(y<n) dfs(x,y+1);
        else dfs(x+1,1);
        return;
    }
    for(int i=2;i<=n*n;i++)
    {
        if(!vst[i]&&check(x,y,i))
        {
            vst[i]=1;
            map[x][y]=i;
            if(y<n) dfs(x,y+1);
            else dfs(x+1,1);
            vst[i]=0;
            map[x][y]=0;
        }
    }

}
int main()
{
    int i,j;
    cin>>n;
    map[1][1]=1;vst[1]=1;
    for(i=1;i<=200;i++)
        if(check(i))b[i]=1;
    dfs(1,1);
    cout<<"NO"<<endl;
    return 0;
}