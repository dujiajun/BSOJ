#include<iostream>
using namespace std;
long long s,a[100005],f[100005],q[100005],minn,n,m,head=1,tail=1,c;
int main()
{  
	cin>>n>>m;minn=1ll<<50;
   	for(int i=1;i<=n;i++){cin>>a[i];s+=a[i];}
   	for(int i=1;i<=n;i++)
   	{
   		f[i]=a[i]+f[q[head]];
   		if(i>=n-m&&f[i]<minn)minn=f[i];
      	while(f[q[tail]]>f[i]&&head<=tail)tail--;
      	q[++tail]=i;
      	while(q[head]<i-m)head++;
   	}
   	cout<<s-minn<<endl;
   	return 0;
}
