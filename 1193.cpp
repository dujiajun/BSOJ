#include<iostream>
using namespace std;
bool vst[300];
int q[300],g[300][300],n;
int main()
{
    cin>>n;
    for(int i=1,x,y;i<=n;i++)
	{
        scanf("%d%d",&x,&y);
        g[y][x]=1;
    }
    int s=0;vst[s]=1;q[1]=s;int h=1,t=1;
    while(h<=t)
	{
		if(q[h]!=0)cout<<q[h]<<" ";
        for(int j=1;j<=n;j++)
        if(!vst[j]&&g[q[h]][j])
		{
            q[++t]=j;
            vst[j]=1;        
        }
        h+=1;
    }
    return 0;
}

