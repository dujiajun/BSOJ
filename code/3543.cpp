#include<iostream>
#include<algorithm>
using namespace std;
string s;
char c[101];
int b[101]={0},a[101]={0},n,t=0;
void d(int k)
{  
	if(k>n)
	{
		t++;
		cout<<t<<":";
		for(int i=1;i<=n;i++)cout<<c[a[i]];
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=1)
		{
			a[k]=i;
			b[i]=1;
			d(k+1);
			b[i]=0;
		}	
	}
}
int main()
{   
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)c[i+1]=s[i];
	sort(c+1,c+n+1);
	d(1);
	return 0;
}
