#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int  c[50];
string s;
int n,f[50],t=0;

void dfs(int deep)
{
	if(deep>n)
	{
		t++;
		cout<<t<<":";
		for(int i=1;i<=n;i++)
		cout<<(char)(c[i]+'a');
		cout<<endl;
	 
	}
	for(int i=0;i<=25;i++)
		if(f[i])
		{
			c[deep]=i;
			f[i]--;
			dfs(deep+1);
			f[i]++;
		}
}

int main()
{
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)
	if(s[i]>='a'&&s[i]<='z')f[s[i]-'a']++;
	dfs(1);
	return 0;
}