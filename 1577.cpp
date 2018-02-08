#include<iostream>
using namespace std;
int n,k;
long long calc(int i,int j)
{
	if(i==0||i<j)return 0;
	if(j==1||j==i)return 1;
	return calc(i-1,j-1)+j*calc(i-1,j);
}
int main()
{
	cin>>n>>k;
	cout<<calc(n,k);
	return 0;
}