#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int count=0,height,a[10];
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	cin>>height;
	for(int i=0;i<10;i++)if(a[i]<=height||a[i]<=height+30)count++;
	cout<<count;
	return 0;
}
