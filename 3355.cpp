#include<iostream>
using namespace std;
int n,x[1000];
int main()
{
	cin>>n;
	n++;
	while(n)
	{
		x[++x[0]]=n%2;
		n/=2;
	}
	for(int i=x[0]-1;i;i--)cout<<(x[i]==0?4:7);
	return 0;
}