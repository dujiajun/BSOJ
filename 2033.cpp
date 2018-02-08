#include<iostream>
using namespace std;
string s;
int n,sum=0,ans=0;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		int x=i,y=i+1;
		while(s[x-1]=='w')x--;
		while(s[y-1]=='w')y++;
		for(int j=i;sum<n;j--)
		{
			if(j==0)j=n;
			if(s[j-1]==s[x-1]||s[j-1]=='w')sum++;
			else break;
		}
		for(int j=i+1;sum<n;j++)
		{
			if(j==n+1)j=1;
			if(s[j-1]==s[y-1]||s[j-1]=='w')sum++;
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}