#include<iostream>
using namespace std;
int n,m,f[105][105]={0};
string s1,s2;
const int sml[6][6]={0, 0, 0, 0, 0, 0,
					 0, 5,-1,-2,-1,-3,
					 0,-1, 5,-3,-2,-4,
					 0,-2,-3, 5,-2,-2,
					 0,-1,-2,-2, 5,-1,
					 0,-3,-4,-2,-1, 0};
const string st=" ACGT ";
//	A	C	G	T	-
//A	5	-1	-2	-1	-3
//C	-1	5	-3	-2	-4
//G	-2	-3	5	-2	-2
//T	-1	-2	-2	5	-1
//-	-3	-4	-2	-1	0
int cmp(char c1,char c2)
{
	int i,j;
	for(i=1;;i++)
		if(c1==st[i])break;
	for(j=1;;j++)
		if(c2==st[j])break;
	return sml[i][j];
}
void init()
{
	cin>>n>>s1>>m>>s2;
}
void dp()
{
	s1=' '+s1;s2=' '+s2;
	f[1][1]=max(cmp(s1[1],s2[1]),max(cmp(s1[1],' '),cmp(s2[1],' ')));
	for(int i=1;i<=n;i++)f[i][0]=f[i-1][0]+cmp(s1[i],' ');
	for(int i=1;i<=m;i++)f[0][i]=f[0][i-1]+cmp(s2[i],' ');
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		f[i][j]=max(f[i-1][j-1]+cmp(s1[i],s2[j]),
				max(f[i-1][j]+cmp(s1[i],' '),
					f[i][j-1]+cmp(' ',s2[j])));
	cout<<f[n][m];
}
int main()
{
	init();
	dp();
	return 0;
} 
/*
7 AGTGATG
5 GTTAG
*/