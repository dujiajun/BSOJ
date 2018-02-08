#include<iostream>
using namespace std;
string s1,s2;
int num;
int main()
{
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++)
	for(int j=0;j<s2.length();j++)num+=(s1[i]-'0')*(s2[j]-'0');
	cout<<num<<endl;
	return 0;
}