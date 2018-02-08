#include<iostream>
using namespace std;
string s;
int bj=0;
int main()
{
	cin>>s;
	if(s[0]=='-')
	{
		cout<<'-';
		s=s.substr(1,s.length()-1);
	}
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]>'0')bj=1;
		if(bj==0)continue;
		cout<<s[i];
	}
	return 0;
}