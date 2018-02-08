#include<iostream>
using namespace std;
int a[1000]={0},b[1000]={0};
void init()
{
	string s1;
	cin>>s1;
	a[0]=s1.length();
	for(int i=1;i<=a[0];i++)a[i]=s1[a[0]-i]-'0';
	b[0]=1;b[1]=1;
}
void jian(int a[],int b[])
{
	for(int i=1;i<=a[0];i++)
	{
		if(a[i]<b[i])
		{
			a[i]=a[i]+10;
			a[i+1]--;
		}
		a[i]=a[i]-b[i];
	}
	while(a[0]>0&&a[a[0]]==0)a[0]--;
}
void chudan(int a[],int num)
{
	int d=0;
	for(int i=a[0];i>=1;i--)
	{
		d=d*10+a[i];
		a[i]=d/num;
		d=d%num;
	}
	while(a[0]>0&&a[a[0]]==0)a[0]--;
}
void out()
{
	if(a[0]==0){cout<<0<<endl;return;}
	for(int i=a[0];i>=1;i--)cout<<a[i];
}
void solve()
{
	if(a[1]%2==1)
	{
		chudan(a,2);
		out();
		return;
	}
	if((a[2]*10+a[1])%4==0)
	{
		chudan(a,2);
		jian(a,b);
		out();
		return;
	}
	chudan(a,2);
	jian(a,b);jian(a,b);
	out();
}
int main()
{
 	init();
 	solve();
	return 0;
}
