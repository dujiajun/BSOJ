#include<iostream>
using namespace std;
int a[1001],g[1001],fmin[1001][1001],fmax[1001][1001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        g[i]=g[i-1]+a[i];
    }
    for(int t=1;t<=n-1;t++)
    for(int i=1;i<=n-t;i++)
	{
        int j=i+t;
        fmax[i][j]=0;
        fmin[i][j]=1<<30;
        for(int k=i;k<=j-1;k++)
		{
            fmin[i][j]=min(fmin[i][j],fmin[i][k]+fmin[k+1][j]);
            fmax[i][j]=max(fmax[i][j],fmax[i][k]+fmax[k+1][j]);
        }
        fmin[i][j]+=(g[j]-g[i-1]);
        fmax[i][j]+=(g[j]-g[i-1]);
    }
    cout<<fmin[1][n]<<" "<<fmax[1][n]<<endl;
    return 0;
}
