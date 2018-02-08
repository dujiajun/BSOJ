#include<iostream>
using namespace std;
 
int main()
{
int n,j;
cin>>n;

if(n<100)j=10;
else if(n<110)j=30;
else if(n<120)j=50;
else if(n<130)j=70;
else if(n>130)j=80;

cout<<j;
return 0;
}
