#include<iostream>
using namespace std;
int n;
void doit(int x)
{
	if(x*2<=n)
	{
		cout<<x;
		cout<<"(";
		doit(x*2);
		if(x*2+1<=n)
		{
			cout<<",";
			doit(x*2+1);
		}
		cout<<")";
	}
	else cout<<x;
}
int main()
{
	cin>>n;
	cout<<"(";
	doit(1);
	cout<<")";
	return 0;
}