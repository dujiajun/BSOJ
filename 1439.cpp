#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[10];
char s[10][5];
double ans=0,f[5][5][5][5][5][5][5][5][5];
double dfs(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9)
{
	if(f[x1][x2][x3][x4][x5][x6][x7][x8][x9]>=0)return f[x1][x2][x3][x4][x5][x6][x7][x8][x9];
	int num=0;
	f[x1][x2][x3][x4][x5][x6][x7][x8][x9]=0;
	for(int i=1;i<=9;i++)
	for(int j=i+1;j<=9;j++)
	if(a[i]>0&&a[j]>0&&s[i][a[i]]==s[j][a[j]])
	{
		num++;
		a[i]--;a[j]--;
		f[x1][x2][x3][x4][x5][x6][x7][x8][x9]+=dfs(a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		a[i]++;a[j]++;
	}
	if(num>0)f[x1][x2][x3][x4][x5][x6][x7][x8][x9]/=num*1.0;
	return f[x1][x2][x3][x4][x5][x6][x7][x8][x9];
}
int main()
{
	char ch1,ch2;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=4;j++){cin>>ch1>>ch2;s[i][j]=ch1;}
		a[i]=4;
	}
	memset(f,128,sizeof(f));
	f[0][0][0][0][0][0][0][0][0]=1;
	f[4][4][4][4][4][4][4][4][4]=dfs(4,4,4,4,4,4,4,4,4);
	cout<<fixed<<setprecision(6)<<f[4][4][4][4][4][4][4][4][4]<<endl;
	return 0;
}
/*
AS 9S 6C KS
JC QH AC KH
7S QD JD KD
QS TS JS 9H
6D TD AD 8S
QC TH KC 8D
8C 9D TC 7C
9C 7H JH 7D
8H 6S AH 6H
*/