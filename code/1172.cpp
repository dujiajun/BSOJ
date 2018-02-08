#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s[100];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		if(s[i]>s[j])swap(s[i],s[j]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
