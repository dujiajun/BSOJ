#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct FM{int to,next,v;}a[30005];
int n,m,h[105]={0},C[105]={0},U[105]={0},cnt=0,in[105]={0},out[105]={0};
void AddEdge(int x,int y,int z)
{   
	a[++cnt].to=y;
    a[cnt].next=h[x];
    a[cnt].v=z;
    h[x]=cnt;
}
void init()
{   
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>C[i]>>U[i];
    for(int i=1,x,y,z;i<=m;i++)
    {  
		cin>>x>>y>>z;
       	AddEdge(x,y,z);
       	in[y]++;
       	out[x]++;
    }
}
void solve()
{   
	int bj=0,W;
	for(int i=1;i<=n;i++&&C[i])
    if(in[i]==0&&C[i]>0)
    {  
		in[i]--;
        for(int k=h[i];k;k=a[k].next)
        {  
			int j=a[k].to;
            C[j]+=a[k].v*C[i];
            in[j]--;
            if(in[j]==0)C[j]-=U[j];
        }
    }
    for(int i=1;i<=n;i++)if(!out[i]&&C[i]>0){cout<<i<<" "<<C[i]<<endl;bj=1;}
    if(!bj)cout<<"NULL"<<endl;
}
int main()
{   
	init();
    solve();
    return 0;
}