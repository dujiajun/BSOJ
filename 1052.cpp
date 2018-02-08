#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int l,s,t,m,ans,a[1005],b[500000],f[500000];
int main()
{
	cin>>l>>s>>t>>m;a[0]=0;
    for(int i=1;i<=m;i++)cin>>a[i];
    if(s==t)
	{
    	for(int i=1;i<=m;i++)if(a[i]%s==0) ans++;
        cout<<ans<<endl;
        exit(0);
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++)
	{
    	int x=a[i]-a[i-1];
        if(x>=90)for(int j=i;j<=m;j++)a[j]-=x-90;
        b[a[i]]=1;
    }
    ans=110;f[0]=0;
    for(int i=1;i<=a[m]+t;i++)f[i]=110;
    for(int i=s;i<=a[m]+t;i++)
    for(int j=i-t;j<=i-s;j++)f[i]=min(f[i],f[j]+b[i]);
    for(int i=a[m];i<=a[m]+t;i++)ans=min(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}