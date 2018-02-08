#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int f[500][500]={0};
string s1,s2;
int main()
{
	cin>>s1>>s2;
	int l1=s1.length(),l2=s2.length();
	for(int i=l1;i>0;i--)s1[i]=s1[i-1];
	for(int i=l2;i>0;i--)s2[i]=s2[i-1];
	for(int i=1;i<=l1;i++)f[i][0]=i;
	for(int i=1;i<=l2;i++)f[0][i]=i;
	for(int i=1;i<=l1;i++)
	  for(int j=1;j<=l2;j++)
	  {
	  	if(s1[i]==s2[j])f[i][j]=f[i-1][j-1];
	  	else f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
	  }
	cout<<f[l1][l2];
	return 0;
}