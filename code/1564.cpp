#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
 	int n,count=0,sum=0,x=0;
 	cin>>n;
 	char test;
 	cin>>test;
 	string s[n];
 	for(int i=0;i<n;i++)
 	{
 		cin>>s[i];
 		if(s[i][0]=='c'&&s[i][1]=='o'&&s[i][2]=='n')count++;
 	}
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<s[i].length();j++)
 		{
 			sum++;
 			if(s[i][j]==test)x++;
 		}
 	}
 	cout<<count<<endl<<fixed<<setprecision(2)<<(double)x/sum*100<<"%";
	return 0;
}
