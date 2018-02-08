#include<iostream>
using namespace std;
int n;
string s;
int main()
{
	cin>>s>>n;
	s=s.substr(s.length()-n,n)+s.substr(0,s.length()-n);
	cout<<s;
	return 0;
}