#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int f[101][101]={0};
int qie(int i,int j)
{
	if(i==j)return 1;
	if(f[i][j]>0)return f[i][j];
	int s=0xfffffff/2;
	for(int k=2;k<=i-1;k++)
	 s=min(s,qie(k,j)+qie(i-k,j));
	for(int k=2;k<=j-1;k++)
	 s=min(s,qie(i,k)+qie(i,j-k));
	f[i][j]=s;
	return s;
}
int main()
{
	int i,j;
	cin>>i>>j;
	cout<<qie(i,j);
	return 0;
}
