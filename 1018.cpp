#include<iostream>
using namespace std;
int a[10005],n,m,k;
int main()
{
	int ans=1,t=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)a[i]=1;
    for(int i=1,x,y;i<=k;i++)
    {
        cin>>x>>y;
        a[x]+=y;
    }
    for(int i=1;i<=n;i++)
    {
        t+=a[i];
        if(t<=m)continue;
        else {ans++;t=a[i];continue;}
    }  
    cout<<ans<<endl;
	return 0;
}
