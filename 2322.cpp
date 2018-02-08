#include<iostream>
using namespace std;

string s1,s2,s3,s;
int l1=1,l2=1,l3=1,f[105][105][105]={0},g[105][105][105]={0};;
void out(int x,int y,int z)
{
	if(x<1||y<1||z<1)return;
	if(g[x][y][z]==0)
	{
		out(x-1,y-1,z-1);
		cout<<s1[x];
	}
	if(g[x][y][z]==1)out(x-1,y,z);
	if(g[x][y][z]==2)out(x,y-1,z);
	if(g[x][y][z]==3)out(x,y,z-1);
}
void dp()
{
	for(int i=1;i<=l1;i++)
	for(int j=1;j<=l2;j++)
	for(int k=1;k<=l3;k++)
	{
		if(s1[i]==s2[j]&&s2[j]==s3[k])
		{
			f[i][j][k]=f[i-1][j-1][k-1]+1;
			g[i][j][k]=0;
		}
		else
		{
			f[i][j][k]=f[i-1][j][k];
			g[i][j][k]=1;
			if(f[i][j][k]<f[i][j-1][k])
			{
				f[i][j][k]=f[i][j-1][k];
				g[i][j][k]=2;
			}
			if(f[i][j][k]<f[i][j][k-1])
			{
				f[i][j][k]=f[i][j][k-1];
				g[i][j][k]=3;
			}
			
		}
	}
	out(l1,l2,l3);
}
int main()
{
	cin>>s1>>s2>>s3;
	l1=s1.length();l2=s2.length();l3=s3.length();
	s1=' '+s1;s2=' '+s2;s3=' '+s3;
	dp();
	return 0;
}
/*
cecqbhvaiaedpibaluk
cabegviapcihlaaugck
adceevfdadaepcialaukd
*/