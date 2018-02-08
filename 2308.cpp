#include<iostream>
using namespace std;
int m,n,k,l,d,rw[1005],ln[1005],vst[1005];
void solve(int n,int t,int a[])
{
    int maxx;
    a[0]=0;
    for(int i=0;i<=1001;i++)vst[i]=0;
    for(int k=1;k<=t;k++)
    {
        maxx=0;
        for(int j=1;j<=n;j++)if(!vst[j]&&a[j]>a[maxx])maxx=j;
        vst[maxx]=1;
    }
    for(int i=1;i<=n;i++)if(vst[i])cout<<i<<" ";
}
void init()
{
    cin>>m>>n>>k>>l>>d;
    for(int i=1,x1,x2,y1,y2;i<=d;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)ln[min(y1,y2)]++;
        if(y1==y2)rw[min(x1,x2)]++;
    }
}
int main()
{
    init();
    solve(m,k,rw);
    cout<<endl;
    solve(n,l,ln);
    return 0;
}
/*
4 5 1 2 3
4 2 4 3
2 3 3 3
2 5 2 4
*/