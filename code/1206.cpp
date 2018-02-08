#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,K,ans=0,vst[10][10]={0},H[10]={0},L[10]={0};
void DFS(int X,int Y)
{
    if(X==N+1){ans++;return;}
    for(int i=Y;i<=N;i++)
    if(!vst[X][i]&&H[X]<K&&L[i]<K)
    {
        vst[X][i]=1;
        H[X]++;L[i]++;
        if(H[X]==K)DFS(X+1,1);else DFS(X,i+1);
        L[i]--;H[X]--;
        vst[X][i]=0;
    }
}
int main()
{ 
    cin>>N>>K;
    DFS(1,1);
    cout<<ans<<endl;
    return 0;
}