#include<iostream>
using namespace std;
int n=1,sum=0;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]!='-')
		{
			sum+=(s[i]-'0')*n;
			n++;
		}
	}
	char c=sum%11+'0';
	if(sum%11==10)c='X';
	if(c==s[s.length()-1])
		cout<<"Right\n";
	else 
	{
		s[s.length()-1]=c;
		cout<<s<<endl;
	}
	return 0;
} 