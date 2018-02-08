#include<iostream>
using namespace std;
string s2,s1;
int m,n,x[100];
int main()
{
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.length();i++)m=m*2+(s2[i]-'0');
	for(int i=0;i<s1.length();i++)n=(n*2+(s1[i]-'0'))%m;
	if(n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	while(n){x[++x[0]]=n%2;n/=2;}
	for(int i=x[0];i;i--)cout<<x[i];
	return 0;
}