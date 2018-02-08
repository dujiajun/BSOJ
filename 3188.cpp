#include<iostream>
using namespace std;
char c[100001];
int f[100001][2]={0},n,top=0,sum=0;
string s;
void cal(char sh,int x,int y)
{
	if(sh=='+')
	{
		f[x][1]=(f[x][1]*(f[y][1]+f[y][0])+f[x][0]*f[y][1])%10007;
		f[x][0]=(f[x][0]*f[y][0])%10007;
	}
	else
	{
		f[x][0]=(f[x][0]*(f[y][1]+f[y][0])+f[x][1]*f[y][0])%10007;
		f[x][1]=(f[x][1]*f[y][1])%10007;
	}
}
int main()
{
	cin>>n>>s;
	top=1;c[1]='(';s+=')';
	f[++sum][0]=f[sum][1]=1;
	for(int i=0;i<=n;i++)
	if(s[i]=='(') c[++top]='(';
	else if(s[i]==')')
	{
		while(c[top]!='(') {cal(c[top],sum-1,sum);top--;sum--;}
		top--;
    }
    else
    {
        while(c[top]!='('&&c[top]<=s[i]){cal(c[top],sum-1,sum);top--;sum--;}
        c[++top]=s[i];
        f[++sum][0]=f[sum][1]=1;
    }
    cout<<f[1][0]<<endl;
    return 0;
}