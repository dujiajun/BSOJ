#include<iostream>
using namespace std;
int a,b,c,d,e,f,ept1,ept2,m,emp2[3]={5,3,1};
int main()
{
	cin>>a>>b>>c>>d>>e>>f;
	m=d+e+f+c/4;
	if(c%4)m++;
	ept2=5*d+emp2[c%4-1];
	if(b>ept2)m+=(b-ept2+8)/9;
	ept1=36*m-36*f-25*e-16*d-9*c-4*b;
	if(a>ept1)m+=(a-ept1+35)/36;
	cout<<m<<endl;
	return 0;
}
