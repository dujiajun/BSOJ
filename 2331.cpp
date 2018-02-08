#include<iostream>
#include<algorithm>
using namespace std;
struct ep{int a,b;}w[1005];
int n,ans=0,f[1005];
bool cmp(ep x,ep y)
{
	if(x.a!=y.a)return x.a<y.a;
	else return x.b<y.b;
}
int main()
{   
	cin>>n;
    for(int i=1;i<=n;i++)
	{cin>>w[i].a>>w[i].b;f[i]=1;}
    sort(w+1,w+n+1,cmp);
    for(int i=2;i<=n;i++)
    	for(int j=1;j<=i-1;j++)
    		if(w[j].b>w[i].b)
				f[i]=max(f[i],f[j]+1);
    for(int i=1;i<=n;i++)
		ans=max(f[i],ans);
    cout<<ans<<endl;
    return 0;
}

