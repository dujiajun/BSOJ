#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
 	char s[1000];
 	int sum=0;
 	gets(s);
 	int length = strlen(s);
 	for(int i=0;i<length;)
 	{
 		if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')
		 {
	 	 sum++;
 		 while(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')
		  i++;
 		 }
 		 else i++;
 	}
 	cout<<sum;
	return 0;
}
