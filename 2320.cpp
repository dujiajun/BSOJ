#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,f[250]={0},len;
string wds[6]={"one","puton","out","output","in","input"},sl;
char tmp[250];
void in_solve_out()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		gets(tmp);
		sl=tmp;sl=' '+sl;
		len=sl.length();
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int i=1;i<len;i++)
		{
			for(int j=0;j<6;j++)
			{
				int len2=wds[j].length();
				if(i>=len2&&f[i-len2]&&sl.substr(i-len2+1,len2)==wds[j])f[i]=1;
			}
		}
		if(f[len-1])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
int main()
{
	in_solve_out();
	return 0;
}
/*
6
puton
inonputin
oneputonininputoutoutput
oneininputwooutoutput
outpu
utput
*/