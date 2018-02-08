#include<iostream>
#include<cstring>
using namespace std;
const string monname[15]={" ","Jan.","Feb.","Mar.","Apr.","May.","June.","July.","Aug.","Sept.","Oct.","Nov.","Dec."};
const string dayess[15]={"th","st","nd","rd","th","th","th","th","th","th"};
int mon[15]={0,31,28,31,30,31,30,31,31,30,31,30,31},pr[1000005]={0},vst[1000005]={0};
int y,num1=0,num2=0,k=0,bj=0;
bool checkyear(int year)
{
	return (year%400==0)||(year%4==0&&year%100!=0);
}
void makepr()
{
	vst[0]=1;vst[1]=1;
	for(int i=2;i<=1000;i++)
	for(int j=i*i;j<=1000000;j+=i)vst[j]=1;
	for(int i=2;i<=1000000;i++)if(!vst[i])pr[++k]=i;
}
bool checknum(int x)
{
	for(int i=1;i<=k&&pr[i]<x;i++)if(x%pr[i]==0)return 0;
	return 1;
}
void out(int year,int month,int day)
{
	cout<<monname[month]<<" ";
	if(day<10)cout<<"0";
	cout<<day;
	if(day==11)cout<<"th";
	else if(day==12)cout<<"th";
	else if(day==13)cout<<"th";
	else cout<<dayess[day%10];
	cout<<" "<<y<<endl;
}
int main()
{
	//freopen("birthday.in","r",stdin);
	//freopen("birthday.out","w",stdout);
	makepr();
	cin>>y;
	if(checkyear(y))mon[2]++;
	for(int i=1;i<=12;i++)
	for(int j=1;j<=mon[i];j++)
	{
		num2=y*10000+i*100+j;
		if(checknum(num2)){out(y,i,j);bj=1;}
	}
	if(!bj)cout<<"Bad luck"<<endl;
	return 0;
}