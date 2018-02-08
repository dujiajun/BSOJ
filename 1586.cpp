#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
 	string s;
 	cin>>s;
 	int flag=0;
 	for(int i=0;i<s.length();i++)
 	{
	    if(s[i]=='@')break;
	    else if(s[i]=='(')flag++;
	    else if(s[i]==')')flag--;
	    if(flag<0){cout<<"NO";return 0;}
 	}
 	if(flag==0)
 	cout<<"YES";
 	else
 	cout<<"NO";
	return 0;
}
