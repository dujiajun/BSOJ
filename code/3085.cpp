#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n,t,f[805][805],a[805];
string s;
bool check(int l,int r)
{
	if(f[l][r]!=-1)return f[l][r];
	if(l==r)return f[l][r]=(s[l]=='0');
	f[l][r]=0;
	if(s[l]!='1'||s[r]!='1')return f[l][r];
	for(int i=l+1;i<r-1;i++)
	if((a[i]-a[l])%2==0&&(a[r-1]-a[i])%2==0)
	if(check(l+1,i)&&check(i+1,r-1))
	{
		f[l][r]=1;
		break;
	}
	return f[l][r];
}
void solve()
{
	cin>>n;
	cin>>s;s=' '+s;
	a[0]=0;
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)a[i]=a[i-1]+int(s[i]-'0');
	if(check(1,n))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main()
{
	cin>>t;
	while(t--)solve();
	return 0;
}
/*
1
10
1100110011
12
10
1111111111
1
22
1110011001111001100111
*/