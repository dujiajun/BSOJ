#include<iostream>
#include<cstring>
using namespace std;
int n,abc[30][5]={0},ans[30]={0},b[30]={0},vst[30]={0};
bool cut()
{
    int a,b,c;
    for(int i=n;i>=1;i--)
    {
        a=ans[abc[i][1]];
        b=ans[abc[i][2]];
        c=ans[abc[i][3]];
        if(!(a==-1||b==-1||c==-1))
        {if((a+b)%n!=c&&(a+b+1)%n!=c) return true;}
        else if(!(a==-1||c==-1||b!=-1))
        {if(vst[(c-a+n)%n]&&vst[(c-a+n-1)%n]) return true;}
        else if(!(b==-1||c==-1||a!=-1))
        {if(vst[(c-b+n)%n]&&vst[(c-b+n-1)%n]) return true;}
        else if(!(a==-1||b==-1||c!=-1))
        {if(vst[(a+b)%n]&&vst[(a+b+1)%n]) return true;}
    }
    return false;
}
bool check()
{
    int k=0;
    for(int i=n;i>=2;i--)
    {
        k=k+ans[abc[i][1]]+ans[abc[i][2]];
        if(k%n!=ans[abc[i][3]]) return false;
        k=k/n;
    }
    k=k+ans[abc[1][1]]+ans[abc[1][2]];
    if(k!=ans[abc[1][3]]) return false;
    return true;
}

void dfs(int x)
{
    if(x==n+1){if(check()){for(int i=1;i<=n;i++)cout<<ans[i]<<" ";exit(0);}return;}
    if(cut())return;
    for(int i=n-1;i>=0;i--)
    if(!vst[i])
    {
        vst[i]=1;
        ans[b[x]]=i;
        dfs(x+1);
        ans[b[x]]=-1;
        vst[i]=0;
    }
}
int main()
{
    int t=0;
    char ch;
    cin>>n;
    for(int i=1;i<=3;i++)
    for(int j=1;j<=n;j++){cin>>ch;abc[j][i]=ch-'A'+1;}
    for(int i=n;i>=1;i--)
    for(int j=1;j<=3;j++)
    if(!vst[abc[i][j]])
    {
        b[++t]=abc[i][j];
        vst[abc[i][j]]=1;
    }
    for(int i=1;i<=26;i++)ans[i]=-1;
    memset(vst,0,sizeof(vst));
    dfs(1);
    return 0;
}