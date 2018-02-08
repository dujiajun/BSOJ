#include<iostream>
#include<cstring>
using namespace std;
int len,all,top,bom,stk[1000030],pos[1000030],l[1000030],ansl,ansr;
string s;
inline int chartoint(char c)
{
	switch(c)
	{
		case '(':return -1;
		case ')':return 1;
		case '[':return -2;
		case ']':return 2;
	}
}
int main()
{
	getline(cin,s);
	memset(l,-1,sizeof(l));
	len=s.length();
	for(int i=0,x;i<len;i++)
	{
		x=chartoint(s[i]);
		if(x+stk[top]==0&&x>0)
		{
			l[i]=pos[top];
			while(l[i]>=1&&l[l[i]-1]!=-1)l[i]=l[l[i]-1];
			if(ansr-ansl<i-l[i])
			{
				ansl=l[i];
				ansr=i;
			}
			top--;
		}
		else
		{
			top++;
			stk[top]=x;
			pos[top]=i;
		}
	}
	for(int i=ansl;i<=ansr;i++)putchar(s[i]);
	return 0;
} 