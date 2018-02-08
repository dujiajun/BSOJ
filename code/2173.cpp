#include<iostream>
#include<map>
using namespace std;
int n,t,m;
string s;
map<string,int>a;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t;
		a[s]=t;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		cout<<a[s]<<endl;
	}
	return 0;
}