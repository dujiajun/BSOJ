#include<iostream>
using namespace std;
int one[10],two[10],thr[10],fou[10],fg[5][5][5][5][5]={0},n1,n2,n3,m1,m2;
char A,B,C,W1,W2;
int cal(int a,int way,int b)
{
	switch(way)
	{
		case 1:return a;
		case 2:return a+b;
		case 3:return a-b;
		case 4:return a*b;	
	}
}
int suan(int nu1,int nu2,int nu3)
{
	int ans=cal(nu1,m1,nu2);
	ans=cal(ans,m2,nu3);
	return ans;
}
bool check()
{
	for(int i=1;i<=7;i++)
		if(thr[i]!=suan(fou[i+n1],fou[i+n2],fou[i+n3]))return 0;
	return 1;
}

void other()
{
	for(int i=1;i<=6;i++)
		two[i]=suan(thr[i+n1],thr[i+n2],thr[i+n3]);
	for(int i=1;i<=5;i++)
		one[i]=suan(two[i+n1],two[i+n2],two[i+n3]);
}
void out()
{
	
	for(int i=1;i<=5;i++)cout<<one[i]<<" ";
	cout<<endl;
	for(int i=1;i<=6;i++)cout<<two[i]<<" ";
	cout<<endl;
	for(int i=1;i<=7;i++)cout<<thr[i]<<" ";
	cout<<endl;
	for(int i=1;i<=8;i++)cout<<fou[i]<<" ";
	cout<<endl;
	
	cout<<"A=";
	if(n1==0)cout<<"B";
	else cout<<"C";
	if(m1!=1)
	{
		if(m1==2)cout<<"+";
		if(m1==3)cout<<"-";
		if(m1==4)cout<<"*";
		if(n2==0)cout<<"B";
		else cout<<"C";
	}
	if(m2!=1)
	{
		if(m2==2)cout<<"+";
		if(m2==3)cout<<"-";
		if(m2==4)cout<<"*";
		if(n3==0)cout<<"B";
		else cout<<"C";
	}
}
int main()
{
	for(int i=1;i<=7;i++)cin>>thr[i];
	for(int i=1;i<=8;i++)cin>>fou[i];
	for(m1=1;m1<=4;m1++)
	for(m2=1;m2<=4;m2++)
	for(n1=0;n1<=1;n1++)
	for(n2=0;n2<=1;n2++)
	for(n3=0;n3<=1;n3++)
	{
		if(check())
		{
			other();
			out();
			return 0;
		}
	}
	return 0;
}
/*
3 4 4 4 4 3 4
1 2 2 2 2 2 1 3
*/