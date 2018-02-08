#include<iostream>
using namespace std;
int main()
{
    int a[10001]={0},b[10001]={0},n,y=1,z=1,c,d,i;
    cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	a[n+1]=a[1];a[n+2]=a[2];a[n+3]=a[3];
	
	for(i=1;i<=n;i++)
	b[i]=a[i]+a[i+1]+a[i+2]+a[i+3];
      c=b[1];
    
	for(i=2;i<=n;i++)
	if(b[i]>c){c=b[i];y=i;}
     d=b[1];
    
	for(i=2;i<=n;i++)
	if(b[i]<d){d=b[i];z=i;}
	cout<<y<<" "<<z;
	return 0;
}