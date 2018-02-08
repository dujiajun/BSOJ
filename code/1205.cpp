#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n[100]={0};
int max1=0;
void chengdan(int a[])
{
     for(int i=1;i<=a[0];i++)a[i]=a[i]*max1;
     for(int i=1;i<=a[0];i++){a[i+1]+=a[i]/10;a[i]%=10;}
     while(a[a[0]+1]>0){a[0]++;a[a[0]+1]+=a[a[0]]/10;a[a[0]]%=10;}
}
void jia(int a[],int x)
{
     a[1]+=x;
     for(int i=1;i<=a[0];i++)
     {a[i+1]+=a[i]/10;
     a[i]%=10;}
     if(a[a[0]+1]>0)a[0]++;
     return;
}
void print(int a[])
{
     if(a[0]==0){cout<<0<<endl;return;}
     for(int i=a[0];i>0;i--)cout<<a[i];
     cout<<endl;
     return;
}

int main()
{
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{if(s[i]-'A'>max1)max1=s[i]-'A';}
	max1++;
	for(int i=0;i<len;i++){chengdan(n);jia(n,s[i]-'A');}
	print(n);
	return 0;
}
