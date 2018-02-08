#include<iostream>
#include<cstring>
using namespace std;
char st[260];
int poskh(int l,int r)
{
	int t=0;
	for(int i=l;i<=r;i++)
	{
		if(st[i]=='(')t++;
		if(st[i]==')')t--;
		if(t==0)return i;
	}
	return -1;
}
int findlow(int l,int r)
{
	int t=0,k=-1;
	for(int i=r;i>=l;i--)
	{
		if(st[i]>='0'&&st[i]<='9')continue;
		if(st[i]==')')t++;
		if(st[i]=='(')t--;
		if((st[i]=='+'||st[i]=='-')&&t==0)return i;
		if((st[i]=='*'||st[i]=='/')&&t==0&&k==-1)k=i;
	}
	return k;
}
int isnum(int l,int r)
{
	int data=0;
	for(int i=l;i<=r;i++)
	{
		if(!(st[i]>='0'&&st[i]<='9'))return -1;
		data=data*10+st[i]-'0';
	}
	return data;
}
int cal(int a,char mark,int b)
{
	switch(mark)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}
int tree(int l,int r)
{
	int tmp,l1,l2,p;
	tmp=isnum(l,r);
	if(tmp!=-1)return tmp;
	if(st[l]=='('&&poskh(l,r)==r)return tree(l+1,r-1);
	p=findlow(l,r);
	l1=tree(l,p-1);
	l2=tree(p+1,r);
	return cal(l1,st[p],l2); 
}
 int main()
{
	cin>>st;
	int len=strlen(st);
	cout<<tree(0,len-1);
	return 0;
}