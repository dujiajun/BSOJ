#include<iostream>
using namespace std;

int main()
{
	int n,a[1000]={0},x,b=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a[x]=1;
	}
	for(int i=0;i<1000;i++)if(a[i]==1)	b++;
	cout<<b<<endl;
	for(int i=0;i<1000;i++)if(a[i]==1)	cout<<i<<" ";
	return 0;
}
