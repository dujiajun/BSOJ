#include<iostream>
using namespace std;
string s;
int len,f[101][101];
int main()
{
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
	for(int j=i;j<len;j++)f[i][j]=0x7fffffff/2;
	for(int i=0;i<len;i++)f[i][i]=1;
	for(int t=2;t<=len;t++)
	for(int i=0;i<len-t+1;i++)
	{
		int j=i+t-1;
		if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']')f[i][j]=f[i+1][j-1];
		for(int k=i;k<j;k++)
		f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
	}
	cout<<f[0][len-1];
	return 0;
} 