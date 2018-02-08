#include<iostream>
#include<cstring>
using namespace std;
char a[25],b[25];
void f(char a[],char b[],int ll)
{
	int i=0;
	while(a[i]!=b[0])i++;
	if(i>0)f(a,b+1,i);
	if(i<ll-1)f(a+i+1,b+i+1,ll-i-1);
	cout<<b[0];
}
int main()
{
	cin>>b>>a;
	f(a,b,strlen(b));
	return 0;
}