#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long toten(long long n,long long x)
{
	long long nn=0,t=0;
	while(1)
	{
		nn=nn+n%10*pow(x,t++);
		n/=10;
		if(n==0)break;
	}
	return nn;
}
long long tento(long long n,long long x)
{
	long long t=0,num[30]={0},nn=0;
	while(1)
	{
		num[++t]=n%x;
		n/=x;
		if(n/x==0&&n%x==0)break;
	}
	for(int i=t;i>=1;i--)
		nn=nn*10+num[i];
	return nn;
}
void init()
{
	string s,num,j1,j2;
	long long k1=0,k2=0,n=0,x=0,to=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='<')k1=i;
		if(s[i]=='>')k2=i;
	}
	num=s.substr(0,k1);
	j1=s.substr(k1+1,k2-k1-1);
	j2=s.substr(k2+1,s.length());
	for(int i=0;i<num.length();i++)n=n*10+num[i]-'0';
	for(int i=0;i<j1.length();i++)x=x*10+j1[i]-'0';
	for(int i=0;i<j2.length();i++)to=to*10+j2[i]-'0';
	cout<<tento(toten(n,x),to)<<endl;
}
int main()
{
	init();
	return 0;
}