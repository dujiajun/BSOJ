#include<iostream>
#include<cstring>
using namespace std;
int n,m,rd[30],g[30][30],ans[30],tem[30],cnt=0,v[30];
char A,B,C;
int topsort()
{
     int k=0,flag=0;
     memcpy(tem,rd,sizeof(rd));
     for(int i=1; i<=cnt; i++)
     {
        k++;
        int j=1,t=0;
        for(int w=1;w<=n;w++)if(tem[w]==0&&v[w])t++,j=w;
        if (t==0)return 0;
        if (t>1)flag=1;
        tem[j]=1<<29;
        ans[i]=j;
        for(int w=1; w<=n; w++)if(g[j][w]>0)tem[w]--;
     }
     if(k==n&&!flag)return 1;
     return 2;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>A>>C>>B;
        if(!v[A-'A'+1])v[A-'A'+1]=1,cnt++;
        if(!v[B-'A'+1])v[B-'A'+1]=1,cnt++;
        if(g[A-'A'+1][B-'A'+1]==0)rd[B-'A'+1]++;
        g[A-'A'+1][B-'A'+1]=1;
        int tt=topsort();
        if(A==B)tt=0;
        if(tt==0){cout<<"Inconsistency found after "<<i<<" relations.";return 0;}
        if(tt==1)
        {
            cout<<"Sorted sequence determined after "<<i<<" relations: ";
            for(int j=1;j<=n;j++)cout<<char(ans[j]+'A'-1);
           	cout<<".";
            return 0;
        }
    }
    cout<<"Sorted sequence cannot be determined.";
	return 0;
}