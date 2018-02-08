#include<iostream>
#include<cstring>
using namespace std;
int fa[500001]={0},l[500001]={0},r[500001]={0};
string s;
int f[500001][3]={0},len;//f[i][1]red f[i][2]green f[i][3]blue
void cin_and_build()
{
	cin>>s;
	len=s.length();
	s=' '+s;
	fa[1]=1;
	for(int i=2;i<=len;i++)
	{
		int j=i-1;
		while(s[j]=='0')j=fa[j];
		fa[i]=j;
		if(s[j]=='2')l[j]=i;
		else r[j]=i;
		s[j]--;
	}
}
void dp()
{
	memset(f,0,sizeof(f));
	for(int i=len;i>=1;i--)
	{
		f[i][1]=max(f[l[i]][2]+f[r[i]][3],f[l[i]][3]+f[r[i]][2]);
		f[i][2]=max(f[l[i]][1]+f[r[i]][3],f[l[i]][3]+f[r[i]][1])+1;
		f[i][3]=max(f[l[i]][2]+f[r[i]][1],f[l[i]][1]+f[r[i]][2]);
	}
	cout<<max(f[1][1],max(f[1][2],f[1][3]))<<" ";
	memset(f,0,sizeof(f));
	for(int i=len;i>=1;i--)
	{
		f[i][1]=min(f[l[i]][2]+f[r[i]][3],f[l[i]][3]+f[r[i]][2]);
		f[i][2]=min(f[l[i]][1]+f[r[i]][3],f[l[i]][3]+f[r[i]][1])+1;
		f[i][3]=min(f[l[i]][2]+f[r[i]][1],f[l[i]][1]+f[r[i]][2]);
	}
	cout<<max(f[1][1],min(f[1][2],f[1][3]));
}
int main()
{
	cin_and_build();
	dp();
	return 0;
}