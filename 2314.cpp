#include<iostream>
#include<algorithm>
using namespace std;
string s1,s2;
int f[55][55]={0},l1,l2,ans=0;
void in_and_format()
{
	cin>>s1>>s2;
	l1=s1.length();
	l2=s2.length();
	s1=' '+s1;
	s2=' '+s2;
	for(int i=1;i<=l1/2;i++)swap(s1[l1-i+1],s1[i]);
	for(int i=1;i<=l2/2;i++)swap(s2[l2-i+1],s2[i]);
}
void dp()
{
	for(int i=1;i<=l1;i++)f[0][i]=-1;
	for(int j=1;j<=l2;j++)f[j][0]=-1;
	
	for(int i=1;i<=l1;i++)
	for(int j=1;j<=l2;j++)
	{
		f[i][j]=f[i-1][j-1];
		if(s1[i]==s2[j])f[i][j]+=2;
		for(int k=1;k<=i;k++)f[i][j]=max(f[i][j],f[k][j]-1);
		for(int k=1;k<=j;k++)f[i][j]=max(f[i][j],f[i][k]-1);
		ans=max(ans,f[i][j]);
	}
	cout<<ans;
}
int main()
{
	in_and_format();
	dp();
	return 0;
} 
/*
AADDEFGGHC
ADCDEGH
*/ 
