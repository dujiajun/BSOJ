#include<iostream>
using namespace std;
const int MOD=1000000007;
int n,d;
long long c[405][405],f[205];
void pre()
{
	for(int i=1;i<=400;i++){c[i][i]=1;c[i][1]=i;}
	for(int i=2;i<=400;i++)
	for(int j=2;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
}
int main()
{
	cin>>d>>n;
	pre();
	f[0]=1;
	for(int i=1;i<=d;i++)
	for(int j=n;j>=1;j--)
	for(int k=1;k<=j;k++)f[j]=(f[j]+((f[j-k]*c[2*j][2*k]%MOD)*c[2*k][k])%MOD)%MOD;
	cout<<f[n]<<endl;
	return 0;
}