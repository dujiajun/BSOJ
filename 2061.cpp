#include<iostream>
using namespace std;
int n;
int ans=6;
int b[7]={0};
const int month1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int month2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool check(int n)
{
	if(n%400==0)return true;
	if(n%4==0&&n%100!=0)return true;
	else return false;
}
int main()
{
	cin>>n;
	for(int i=1900;i<1900+n;i++)
		for(int j=1;j<=12;j++)
		{
			b[ans%7]++;
			if(check(i))ans+=month2[j];
			else ans+=month1[j];
		}
	cout<<b[6]<<" "<<b[0]<<" ";
	for(int i=1;i<=5;i++)cout<<b[i]<<" ";
	return 0;
} 