#include<iostream>
using namespace std;
int mem[1000]={0};
int f(int n)
{
	if(mem[n]!=0)return mem[n];
	int s=1;
	for(int i=1;i<=n/2;i++)s+=f(i);
	mem[n]=s;
	return s;
}
int main()
{
 	int n;
 	cin>>n;
 	cout<<f(n);
	return 0;
}
