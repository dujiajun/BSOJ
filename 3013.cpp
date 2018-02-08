#include<iostream>
using namespace std;
int m,a[20],b[20],x,n=0,t=1,ans=0;
string s;
void out(int c)
{
	if(c)
	{
		out(c/m);
		cout<<b[c%m];
	}
}
int main()
{
	cin>>m;
	for(int i=1,c;i<=m;i++){cin>>c;a[c]=1;}
	for(int i=0;i<10;i++)if(a[i])
	{
		a[i]=n;
		b[n]=i;
		n++;
	}
	cin>>s;
	for(int i=s.length()-1;i>=0;i--)
	{
		ans+=a[s[i]-'0']*t;
		if(i)t*=m;
	}
	cout<<ans<<endl;
	cin>>x;
	if(x==0)cout<<0<<endl;
	else out(x);
	return 0;
}