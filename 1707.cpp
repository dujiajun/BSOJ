#include <iostream>
using namespace std;
int a[101][20001],row[20001],maxr=0;
int main() 
{
    int m, n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
	{
        row[i]=a[1][i];
        for(int j=1;j<=m;j++)row[i]=max(row[i],a[j][i]);
    }
    for (int j=1;j<=n;j++)
	{
        row[j]=max(0,row[j-1])+row[j];
        maxr=max(maxr,row[j]);
    }
    cout<<maxr<<endl;
    return 0;
}