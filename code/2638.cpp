#include<iostream>
using namespace std;
int a1[27]={0},a2[27]={0},a3[101]={0};
int l1,l2,l3,bj=1;
string s1,s2,s3;
int main()
{
   	cin>>s1>>s2>>s3;
   	l1=s1.length();l2=l1;
   	l3=s3.length();
   	for(int i=0;i<l1;i++)
   	{  
   		if((s2[i]-'A'+1)!=a1[s1[i]-'A'+1]&&a1[s1[i]-'A'+1]!=0){cout<<"Failed";return 0;}
      	if((s1[i]-'A'+1)!=a2[s2[i]-'A'+1]&&a2[s2[i]-'A'+1]!=0){cout<<"Failed";return 0;}
      	a1[s1[i]-'A'+1]=s2[i]-'A'+1;
      	a2[s2[i]-'A'+1]=s1[i]-'A'+1;
   	}
   	for(int i=1;i<=26;i++)if(a1[i]==0){cout<<"Failed";return 0;}
   	for(int i=0;i<l3;i++)
   	{  
	   	if(a1[s3[i]-'A'+1]==0){cout<<"Failed";return 0;}
      	a3[i]=a1[s3[i]-'A'+1];
   	}
   	for(int i=0;i<l3;i++)cout<<char(a3[i]+'A'-1);
   	return 0;
}