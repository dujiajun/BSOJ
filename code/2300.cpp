#include<iostream>
using namespace std;
int cnt[26]={0},minn=1000,maxx=0,
	map[36]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,0};
string s;
bool check(int n)
{
	for(int i=0;i<25;i++)
		if(n==map[i])return true;
	return false;
}
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)cnt[s[i]-'a']++;
	for(int i=0;i<26;i++)
		if(cnt[i]!=0)
		{
			maxx=max(cnt[i],maxx);
			minn=min(cnt[i],minn);
		}
	if(check(maxx-minn))
		cout<<"Lucky Word"<<endl<<maxx-minn;
	else cout<<"No Answer"<<endl<<0<<endl;
	return 0;
}