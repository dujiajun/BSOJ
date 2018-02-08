#include<iostream>
using namespace std;
string name[30000];
int b[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
long long a[30000];
long long gett(string s)
{
	long long tmp=0;
	for(int i=0;i<s.length();i++)tmp=tmp*10+b[s[i]-'A'];
	return tmp;
}
void init()
{
	for(int i=1;i<=24829;i++)
	{
		cin>>name[i];
		a[i]=gett(name[i]);
	}
}
void solve()
{
	long long tag;
	int flag=0;
	cin>>tag;
	for(int i=1;i<=24829;i++)
		if(a[i]==tag){cout<<name[i]<<endl;flag=1;}
	if(flag==0)cout<<"NONE"<<endl;
}
int main()
{
	init();
	solve();
	return 0;
} 