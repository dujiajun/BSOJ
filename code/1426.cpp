#include<iostream>
using namespace std;
int n,f[10001]={0},ans=0;
string s[10001],t;
bool check(int x,int y)
{
	if(s[x].length()>s[y].length())return 0;
	for(int i=0;i<s[x].length();i++)if(s[x][i]!=s[y][i])return 0;
	return 1;
}
int main()
{
	//freopen("link.in","r",stdin);
	//freopen("link.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>s[i];f[i]=1;}
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)if(check(j,i)){f[i]=f[j]+1;break;}	
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}