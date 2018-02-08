#include<iostream>
#include<algorithm>
using namespace std;
int a[505][505],n,x,ans=0;
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++){cin>>a[i][j];a[j][i]=a[i][j];}
    for(int i=1;i<=n;i++)sort(a[i]+1,a[i]+n+1);
    for(int i=1;i<=n;i++)ans=max(ans,a[i][n-1]);
    cout<<1<<endl<<ans<<endl;
    return 0;
}
/*
6
5 28 16 29 27
23 3 20 1
8 32 26
33 11
12
*/