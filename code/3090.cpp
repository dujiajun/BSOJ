#include<iostream>
using namespace std;
string s;
int n;
int xfind(int x)
{
	int t=1;
	while(t)
	{
		x++;
		if(s[x]=='[')t++;
		if(s[x]==']')t--;
	}
	return x;
}
string solve(int l,int r)
{
	int t=0;
	while(s[l]>='0'&&s[l]<='9')t=t*10+s[l++]-'0';
	if(t==0)t=1;
	string tmp1="",tmp2="";
	while(l<=r)
	{
		if(s[l]>='A'&&s[l]<='Z')tmp1+=s[l++];
		else
		{
			int pos=xfind(l);
			tmp1+=solve(l+1,pos-1);
			l=pos+1;
		}
	}
	while(t--)tmp2+=tmp1;
	return tmp2;
}
int main()
{
	cin>>s;
	n=s.length();
	cout<<solve(0,n-1);
	return 0;
}
//A[3F[3B][3C]]