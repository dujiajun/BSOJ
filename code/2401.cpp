#include<iostream>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)break;
		if(n%2!=0)cout<<"Bob\n";
		else cout<<"Alice\n";
	}
	return 0;
} 