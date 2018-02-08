#include<iostream>
#include<map>
#include<algorithm>
#include<cstdlib>
using namespace std;
string s[55],v[10];
int n;
void dfs(string st,int dp)
{
	int pos=-1;
	for(int i=0;i<st.length();i++)if(st[i]=='/'){pos=i;break;}
	if(pos==-1)return;
	string tmp="";
	for(int i=pos+1;i<st.length();i++)
	{
		if(st[i]=='/')break;
		tmp=tmp+st[i];
	}
	if(tmp!=v[dp])
	{
		for(int i=dp;i<=8;i++)v[i]="";
		v[dp]=tmp;
		for(int i=1;i<dp;i++)cout<<"|    ";
		cout<<"|----"<<tmp<<endl;
	}
	dfs(st.substr(pos+1,st.length()-pos-1),dp+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=s[i]+'/';
	}
	sort(s+1,s+n+1);
	for(int i=0;;i++)
	{
		if(s[1][i]=='/')break;
		cout<<s[1][i];
	}
	cout<<endl;
	for(int i=1;i<=n;i++)dfs(s[i],1);
	return 0;
}