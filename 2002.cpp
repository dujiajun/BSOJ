#include<iostream>
#include<cstring>
using namespace std;
struct BIGNUM 
{
    int len,s[50];
    static const int base=10000;
    friend BIGNUM operator*(const BIGNUM&,const int&);
    friend BIGNUM operator+(const BIGNUM&,const BIGNUM&);
    friend bool operator>(const BIGNUM&,const BIGNUM&);
    friend ostream &operator<<(ostream&,BIGNUM&);
    BIGNUM operator=(int);
    BIGNUM(){len=0;memset(s,0,sizeof(s));};
};
BIGNUM BIGNUM::operator=(int a) 
{
    memset(s,0,sizeof(s));
    len=0;
    while (a) 
	{
        s[len++]+=a%BIGNUM::base;
        a/=BIGNUM::base;
    }
    len--;
    return *this;
}
bool operator>(const BIGNUM &a,const BIGNUM &b) 
{
    if (a.len>b.len) return true;
    if (a.len<b.len) return false;
    for (int i=a.len;i>=0;i--) {
        if (a.s[i]>b.s[i]) return true;
        else
            if (a.s[i]<b.s[i]) return false;
    }
    return false;
}
BIGNUM operator+(const BIGNUM &a,const BIGNUM &b) 
{
    BIGNUM c;
    c.len=max(a.len,b.len);
    for (int i=0;i<=c.len;i++)c.s[i]=a.s[i]+b.s[i];
    for (int i=0;i<=c.len;i++) 
	{
        c.s[i+1]+=c.s[i]/BIGNUM::base;
        c.s[i]%=BIGNUM::base;
    }
    if (c.s[c.len+1]!=0) c.len++;
    return c;
}
BIGNUM operator+(const int &aa,const BIGNUM &b) 
{
    BIGNUM a;
    a=aa;
    return a+b;
}
BIGNUM operator+(const BIGNUM &b,const int &aa) 
{
    BIGNUM a;
    a=aa;
    return a+b;
}
ostream &operator<<(ostream &output,BIGNUM &c) 
{
    output<<c.s[c.len];
    for (int i=c.len-1;i>=0;i--) 
	{
        int k=BIGNUM::base;
        while (k>10) 
		{
            k/=10;
            if (c.s[i]<k) output<<'0';
        }
        output<<c.s[i];
    }
    return output;
}
int n, m;
int a[100];
BIGNUM f[100][100];
bool vst[100][100];
BIGNUM dp(int x,int y) 
{
    if (vst[x][y]) return f[x][y];
    vst[x][y]=1;BIGNUM t;
    if (y-x>1) 
	{
        f[x][y]=dp(x+1,y)+dp(x+1,y) + a[x];
        t=dp(x,y-1)+dp(x,y-1) + a[y];
        if (t>f[x][y]) f[x][y]=t;
        return f[x][y];
    }
    else
	{
        if (a[x]>a[y])f[x][y]=(a[x]+a[x]+a[y]);
        else f[x][y]=(a[x]+a[y]+a[y]);
        return f[x][y];
    }
}

int main() 
{
    BIGNUM ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
	{
        memset(a,0,sizeof(a));
    	for(int i=1;i<=m;i++)cin>>a[i];
    	memset(vst,false,sizeof(vst));
        ans=ans+dp(1,m)+dp(1,m);
    }
    cout<<ans<<endl;
    return 0;
}