#include<iostream>
using namespace std;
int n,a[100005]={0};
int main()
{
	cin>>n;
	for(int i=1,t;i<=n-2;i++){cin>>t;a[t]=1;}
	for(int i=1;i<=n;i++)if(a[i]==0)cout<<i<<" ";
	return 0;
}