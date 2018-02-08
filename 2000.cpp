#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[200000];
int main()
{
 	int n,count=1;
 	cin>>n;
 	for(int i=0;i<n;i++)
 	{
 		cin>>a[i];
 	}
 	sort(a+0,a+n);
 	for(int i=1;i<=n;i++)
 	{
 		if(a[i]==a[i-1])count++;
 		if(a[i]!=a[i-1])
 		{
 			cout<<a[i-1]<<" "<<count<<endl;
 			count=1;
 		}
 	}
	return 0;
}
