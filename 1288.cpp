#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
char s[45];
int main()
{
	
	char c1,c2,way;
	gets(s);
	string ans=string(s);
	int n,m=ans.length();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string ans=string(s);
		cin>>way;
		switch(way)
		{
			case 'R':
				cin>>c1>>c2;
				for(int i=0;i<m;i++)if(ans[i]==c1)ans[i]=c2;
				break;
			case 'D':
				cin>>c1;
				for(int i=0;i<m;i++)if(ans[i]==c1)
				{
					ans.erase(ans.find(c1),1);
					break;
				}
				break;
			case 'I':
				cin>>c1>>c2;
				for(int i=m-1;i>=0;i--)if(ans[i]==c1)
				{
					ans.insert(ans.rfind(c1),1,c2);
					break;
				}
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
This is a book.
1
D s 
*/