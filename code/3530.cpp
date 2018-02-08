#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{int a,b,id;}a[1005],k;
int n,m;
const int MAXN=20000;
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
	BIGNUM operator/(const int &a)
	{
		BIGNUM c;
		c.len=len;
		int d=0;
		for(int i=len-1;i>=0;i--)
		{
			d=d*10+s[i];
			c.s[i]=d/a;
			d%=a;
		}
		while(c.len>1&&c.s[c.len-1]==0)c.len--;
		return c;
	}
	bool operator<(const BIGNUM &x)const
	{
		if(len!=x.len)return len<x.len;
		for(int i=len-1;i>=0;--i)if(s[i]!=x.s[i])return s[i]<x.s[i];
		return false;
	}
	bool operator>(const BIGNUM &x)const{return x<*this;}
	bool operator<=(const BIGNUM &x)const{return !(x<*this);}
	bool operator>=(const BIGNUM &x)const{return !(*this<x);}
	bool operator==(const BIGNUM &x)const{return !(x<*this||*this<x);}
	bool operator!=(const BIGNUM &x)const{return x<*this||*this<x;}
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
inline bool cmp(node n1,node n2){return n1.a*n1.b<n2.a*n2.b;}
int main()
{
	cin>>n>>k.a>>k.b;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].a,&a[i].b);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	BIGNUM ji=k.a,ans=1,maxx=1;
	for(int i=1;i<=n;i++)
	{
		ans=ji/a[i].b;
		if(maxx<ans)maxx=ans;
		ji=ji*a[i].a;
	}
	cout<<maxx<<endl;
	return 0;
} 