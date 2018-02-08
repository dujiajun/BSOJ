#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int f[3001][3001]={0};
string s1,s2;
int main()
{
	cin>>s1>>s2;
	int l1=s1.length();	int l2=s2.length();
	s1=' '+s1;	s2=' '+s2;
	for(int i=1;i<=l1;i++)
	for(int j=1;j<=l2;j++)
	{
		if(s1[i]==s2[j])f[i][j]=f[i-1][j-1]+1;
		else f[i][j]=max(f[i-1][j],f[i][j-1]);
	}
	cout<<f[l1][l2];
	return 0;
}
