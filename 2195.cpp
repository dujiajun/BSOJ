#include<iostream>
using namespace std;
int n,b,a[25],f[1000005],sum;
int main()
{
	cin>>n>>b;f[0]=1;
	for(int i=1;i<=n;i++){cin>>a[i];sum+=a[i];}
	for(int i=1;i<=n;i++)
	for(int j=sum;j>=a[i];j--)f[j]=f[j]||f[j-a[i]];
	for(int i=b;i<=sum;i++)
	if(f[i]){cout<<i-b<<endl;return 0;}
	return 0;
}