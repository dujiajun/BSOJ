#include<iostream>
#include<algorithm>
using namespace std;
int n,a[50001]={0};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
	for(int i=n;i>=1;i--)cout<<a[i]<<" ";
	return 0;
}
/*
6
8 3 12 6 34 12
*/