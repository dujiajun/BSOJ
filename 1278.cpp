#include<iostream>
using namespace std;
int main()
{
	long long n,m,x=0,y=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i==j)x+=(n-i+1)*(m-j+1);
		else y+=(n-i+1)*(m-j+1);
	}
	cout<<x<<" "<<y;
	return 0;
}