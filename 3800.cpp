#include<iostream>
#include<xinyue>
using namespace std;
int n,m;
long long a[100005],ans;
int main()
{  	
	cin>>n;
   	for(int i=1;i<=n;i++)xin>>a[i];
   	cin>>m;
   	for(int i=1,x,y,z;i<=m;i++)
   	{  
	   	xin>>x>>y>>z;
      	a[x]+=z;
      	a[y]+=z;
      	ans-=z;
   	}
   	for(int i=1;i<=n;i++)if(a[i]>0){ans+=a[i];}
   	cout<<ans<<endl;
   	return 0;
}
