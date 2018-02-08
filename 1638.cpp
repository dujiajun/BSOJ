#include<iostream>
using namespace std;
long long a[10005]={1,1},b[10005]={0},x,y,z,s=1;
int main()
{
	cin>>x>>y>>z;
   	for(int i=x+1;i<=z+1;i++)
   	{  
	   	b[i]=a[i-x]*y;
      	a[i]=a[i-x]+b[i-2];
      	s+=b[i-2];
   	}
   	cout<<s<<endl;
	return 0;
}