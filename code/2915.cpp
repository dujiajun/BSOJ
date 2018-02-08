#include<iostream>
using namespace std;
int n,l,r,ans=-0x7fffffff/2;
int a[400001],q[400001],f[400001];
int main()
{  
	cin>>n>>l>>r;
   	for(int i=0;i<=n;i++)cin>>a[i];
   	int k,h=1,t=1;
   	for(int i=0;i<=n;i++)f[i]=-0x7fffffff/2;
   	h=1;t=1;q[1]=0;f[0]=0;
   	for(int i=l;i<=n;i++)
   	{  
	   	while(h<=t&&i-r>q[h])h++;
      	if(i-r<=q[h]&&q[h]<=i-l)f[i]=f[q[h]]+a[i];
      	while(h<=t&&f[i-l+1]>f[q[t]])t--;
      	q[++t]=i-l+1;
   	}
   	for(int i=n;i>n-r;i--)if(f[i]>ans){ans=f[i];k=i;}
   	cout<<ans<<endl;
   	return 0;
}