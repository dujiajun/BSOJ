#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=4000;
class BIGNUM
{
	public:
	int len,s[MAXN];
	BIGNUM(){len=1;memset(s,0,sizeof(s));}
	
	BIGNUM(int num)
	{
		*this=num;
	}
	BIGNUM(const char* num)
	{
		*this=num;
	}
	
	BIGNUM operator=(const char* num)
	{
		len=strlen(num);
		for(int i=0;i<len;++i)s[i]=num[len-i-1]-'0';
		return *this;
	}
	BIGNUM operator=(const int num)
	{
		char a[MAXN];
		sprintf(a,"%d",num);
		*this = a;
		return *this;
	}
	BIGNUM operator+(const BIGNUM &a)
	{
		BIGNUM c;
		c.len=max(len,a.len)+1;
		for(int i=0,x=0;i<c.len;++i)
		{
			c.s[i]=s[i]+a.s[i]+x;
			x=c.s[i]/10;
			c.s[i]=c.s[i]%10;
		}
		if(c.s[c.len-1]==0)--c.len;
		return c;
	}
	BIGNUM operator+=(const BIGNUM &a)
	{
		*this=*this+a;
		return *this;
	}

	BIGNUM operator*(const BIGNUM &x)
	{
		BIGNUM c;
		c.len=len+x.len;
		for(int i=0;i<len;++i)
		{
			for(int j=0;j<x.len;++j)
			{
				c.s[i+j]+=s[i]*x.s[j];
				c.s[i+j+1]+=c.s[i+j]/10;
				c.s[i+j]%=10;
			}
		}
		if(c.s[c.len-1]==0)--c.len;
		return c;
	}
	BIGNUM operator*(const int &n)
	{
		BIGNUM c;
		for(int i=0;i<c.len;i++)c.s[i]=s[i]*n;
		for(int i=0;i<c.len;i++)
		{
			c.s[i+1]+=c.s[i]/10;
			c.s[i]=c.s[i]%n;
		}
		return c;
	}
	
	BIGNUM operator*=(const BIGNUM &a)
	{
		*this=*this*a;
		return *this;
	}
	
};

ostream& operator<<(ostream &out,BIGNUM &x)
{
	for(int i=x.len-1;i>=0;--i)
	out<<x.s[i];
	return out;
}

istream& operator>>(istream &in,BIGNUM &x)
{
	char num[MAXN];
	in>>num;
	x=num;
	return in;
}


int main()
{
	BIGNUM sum=0;
	BIGNUM a=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a*=i;
		sum+=a;
	}
	cout<<sum;
	return 0;
}