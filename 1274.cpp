#include<iostream>
using namespace std;
void doit(int x)
{
	if(x==1){cout<<"2(0)";return;}
	//if(x==2){cout<<"2";return;}
	int t=1,i=0;
	while(t*2<=x){t=t*2;i++;}
	cout<<2;
	if(i>1){cout<<"(";doit(i);cout<<")";}
	if(x-t){cout<<"+";doit(x-t);}
}
int main()
{
	int n;
	cin>>n;
	doit(n);
	return 0;
}