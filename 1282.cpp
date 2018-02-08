#include<iostream>
using namespace std;
string s;
int t=0,len;
int main()
{
	cin>>s;len=s.length();
	if(len==1&&(s!="a"&&s!="b"&&s!="c")){cout<<"error 3"<<endl;return 0;}
	for(int i=0;i<len;i++)//判断 error 1和 2 
	{
		if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')'&&s[i]!='a'&&s[i]!='c'&&s[i]!='b'){cout<<"error 1"<<endl;return 0;}
		if(s[i]=='(')t++;
		if(s[i]==')')t--;
		if(t<0){cout<<"error 2"<<endl;return 0;}
	}
	if(t!=0){cout<<"error 2"<<endl;return 0;}
	for(int i=1;i<len;i++)//判断 error 3
	{
		if(s[i]=='(')
		{
			if(s[i-1]=='a'||s[i-1]=='b'||s[i-1]=='c'){cout<<"error 3"<<endl;return 0;}
			if(s[i+1]==')'||s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/'){cout<<"error 3"<<endl;return 0;}
		}
		if(s[i]==')')
		{
			if(s[i+1]=='a'||s[i+1]=='b'||s[i+1]=='c'){cout<<"error 3"<<endl;return 0;}
			if(s[i-1]=='('||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'){cout<<"error 3"<<endl;return 0;}
		}
		
		if(s[i]=='a'||s[i]=='b'||s[i]=='c')
		{
			if(s[i-1]=='a'||s[i-1]=='b'||s[i-1]=='c'){cout<<"error 3"<<endl;return 0;}
			if(s[i+1]=='a'||s[i+1]=='b'||s[i+1]=='c'){cout<<"error 3"<<endl;return 0;}
		}
		if(s[i]=='*'||s[i]=='-'||s[i]=='+'||s[i]=='/')
			if(s[i-1]!='a'&&s[i-1]!='b'&&s[i-1]!='c'){cout<<"error 3"<<endl;return 0;}
	}
	cout<<"OK"<<endl;
	return 0;
}