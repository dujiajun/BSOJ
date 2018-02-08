#include<iostream>
using namespace std;
int n,x[100],y[100],s=0;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	x[n]=x[0],y[n]=y[0];
	for(int i=0;i<n;i++)s+=x[i]*y[i+1]-y[i]*x[i+1];
	cout<<s/2;
	return 0;
}
/*
10
0 0
4 0
4 1
3 1
3 3
2 3
2 2
1 2
1 3
0 3
*/