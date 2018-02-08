#include<iostream>
using namespace std;
string s;
int a[101]={0},b[101]={0},n,m;
void d(int k)
{  
	if(k>m)
	{
		for(int i=1;i<=m;i++)
		cout<<s[a[i]-1];
		cout<<endl;}
	else for(int i=a[k-1]+1;i<=n;i++)
	{
		a[k]=i;
		b[i]=1;
		d(k+1);
		b[i]=0;
	}
}
int main()
{   
	cin>>s>>m;
	n=s.length();
	d(1);
	return 0;
}
