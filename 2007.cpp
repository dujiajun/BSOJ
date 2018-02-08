#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=40000;
struct BIGNUM
{
	int len,s[MAXN];
	BIGNUM(){len=1;memset(s,0,sizeof(s));}
	BIGNUM(int num){*this=num;}
	BIGNUM(const char* num){*this=num;}
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
		*this=a;
		return *this;
	}
	BIGNUM operator-(const BIGNUM &a)
	{
		BIGNUM c;
		c.len=max(len,a.len);
		BIGNUM temp1=a;
		BIGNUM temp2=*this;
		if(temp2<temp1)
		{
			c.len++;
			for(int i=0;i<c.len-1;++i)
			{
 			 	if(temp2.s[i]>temp1.s[i]){temp1.s[i]+=10;temp1.s[i+1]--;}
			 	c.s[i]=temp1.s[i]-temp2.s[i];
			}
			for(int i=c.len-1;;i--)
			{
				if(c.s[i]==0)--c.len;
				else {cout<<"-";break;}
			}
			return c;
		}
		else
		{
			for(int i=0;i<c.len;++i)
			{
				if(temp1.s[i]>temp2.s[i]){temp2.s[i]+=10;temp2.s[i+1]--;}
				c.s[i]=temp2.s[i]-temp1.s[i];
			}
			if(c.s[len-1]==0)--c.len;
			return c;
		}
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
	bool operator<(const BIGNUM &x)const
	{
		if(len!=x.len)return len<x.len;
		for(int i=len-1;i>=0;--i)if(s[i]!=x.s[i])return s[i]<x.s[i];
		return false;
	}
};
ostream& operator<<(ostream &out,BIGNUM &x)
{
	for(int i=x.len-1;i>=0;i--)out<<x.s[i];
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
	int n;
	cin>>n;
	BIGNUM a=1;
	for(int i=1;i<=n+1;i++)a=a*2;
	a=a-2;
	cout<<a;
	return 0;
}