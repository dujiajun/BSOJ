#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int k,l1,l2,f[2005][2005]={0};
string s1,s2;
void init()
{
	cin>>s1>>s2>>k;
	l1=s1.length();
	l2=s2.length();
	s1=' '+s1;
	s2=' '+s2;	
	for(int i=1;i<=l1;i++)f[i][0]=i*k;
	for(int j=1;j<=l2;j++)f[0][j]=j*k;
}
void dp()
{
	for(int i=1;i<=l1;i++)
	for(int j=1;j<=l2;j++)
		f[i][j]=min(f[i-1][j-1]+abs(s1[i]-s2[j]),min(f[i-1][j]+k,f[i][j-1]+k));
	cout<<f[l1][l2]<<endl;
}
int main()
{
	init();
	dp();
	return 0;
}
/*
cmc
snmn
2
*/