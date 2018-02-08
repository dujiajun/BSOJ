#include<iostream>
using namespace std;
int a[10001]={0},b[10001]={0},n,l;
string s;
bool check()
{
	for(int i=1;i<=l/2;i++)if(a[i]!=a[l-i+1])return false;
	return true;
}
void getb()
{
	for(int i=1;i<=l;i++)b[i]=a[l-i+1];
}
void jia()
{
	for(int i=1;i<=l;i++)a[i]+=b[i];
	for(int i=1;i<=l;i++)
	{
		a[i+1]+=a[i]/n;
		a[i]=a[i]%n;
	}
	if(a[l+1])l++;
}
int main()
{
	cin>>n>>s;l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]-'0'<=9)a[i+1]=s[i]-'0';
		else a[i+1]=s[i]-'A'+10;
	}
	int i=0;
	while(i<=30)
	{
		if(!check()){getb();jia();i++;}
		else {cout<<i<<endl;return 0;}
	}
	cout<<"Impossible"<<endl;
	return 0;
}