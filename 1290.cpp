#include<iostream>
using namespace std;
int tl=0,a[7]={0},b[1005]={0};
int main()
{
	for(int i=1;i<=6;i++)cin>>a[i];
	for(int i=0;i<=a[1];i++)
	for(int j=0;j<=a[2];j++)
	for(int k=0;k<=a[3];k++)
	for(int l=0;l<=a[4];l++)
	for(int m=0;m<=a[5];m++)
	for(int n=0;n<=a[6];n++)
		b[i+2*j+3*k+5*l+10*m+20*n]++;
	for(int i=1;i<=1005;i++)
		if(b[i])tl++;
	cout<<"TOTAL="<<tl<<endl;
	return 0;
}