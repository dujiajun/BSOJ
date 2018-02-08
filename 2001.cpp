#include<iostream>
using namespace std;
int p1,p2,p3,len;
string s;
int cmp(int x)
{
	if(s[x]>='0'&&s[x]<='9')return 1;
	if(s[x]>='a'&&s[x]<='z')return 0;
	if(s[x]>='A'&&s[x]<='Z')return -1;
}
void doit(int x,int y)
{
	char st=s[x],ed=s[y];
	if(cmp(x)!=cmp(y)){cout<<'-';return;}
	if(s[y]<=s[x]){cout<<'-';return;}
	if(s[x]+1==s[y])return;
	if(cmp(x)==-1&&p1==1){st+=32;ed+=32;}
    if(cmp(x)==0&&p1==2){st-=32;ed-=32;}
    if(p1==3)
    {
    	for(int i=1;i<=(ed-st-1)*p2;i++)cout<<'*';
		return;
    }
	if(p3==1)
	{
		for(char i=st+1;i<ed;i++)
		for(int j=1;j<=p2;j++)cout<<i;
		return ;
	}
	if(p3==2)
	{
		for(char i=ed-1;i>st;i--)
		for(int j=1;j<=p2;j++)cout<<i;
		return ;
	}
}
int main()
{
	cin>>p1>>p2>>p3>>s;
	int i=0;
    while(s[i]=='-'){cout<<s[i];i++;}
	for(;i<s.length();i++)
	{
		if(s[i]=='-'){doit(i-1,i+1);continue;}
		cout<<s[i];
	}
	return 0;
}