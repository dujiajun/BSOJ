#include<iostream>
using namespace std;
int n,f[110][11][11][11]={0};
bool g[110][11][11][11]={0};
char ch[110];
int dp(int k,int a,int b,int c)
{
	int j=a+b+c;
	for(int i=1;i<=10-j;i++)
	{
		k++;
		if(k>n)break;
		if(ch[k]=='A')a++;
		if(ch[k]=='B')b++;
		if(ch[k]=='C')c++;
	}
	if(k>=n)
	{
		g[k][a][b][c]=1;
		f[k][a][b][c]=(a>0)+(b>0)+(c>0);
		return f[k][a][b][c];
	}
	if(!g[k][a][b][c])
	{
		g[k][a][b][c]=1;
		f[k][a][b][c]=1<<29;
		if(a>0)f[k][a][b][c]=min(f[k][a][b][c],dp(k,0,b,c)+1);
		if(b>0)f[k][a][b][c]=min(f[k][a][b][c],dp(k,a,0,c)+1);
		if(c>0)f[k][a][b][c]=min(f[k][a][b][c],dp(k,a,b,0)+1);
	}
	return f[k][a][b][c];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ch[i];
	cout<<dp(0,0,0,0)<<endl;
	return 0;
} 