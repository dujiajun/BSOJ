#include<iostream>
using namespace std;
string s;
int n,t,usd[30],f[35];
void dfs(int dp)
{
	if(dp>n)
	{
		t++;
		cout<<t<<":";
		for(int i=1;i<=n;i++)cout<<char(f[i]+'a'-1);
		cout<<endl;
		return;
	}
	for(int i=f[dp-1];i<=26;i++)
	if(usd[i]>0)
	{
		usd[i]--;
		f[dp]=i;
		dfs(dp+1);
		usd[i]++;
	}
}
int main()
{
	cin>>s>>n;
	for(int i=0;i<s.length();i++)usd[s[i]-'a'+1]++;
	dfs(1);
	return 0;
}