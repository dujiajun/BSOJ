#include<iostream>
using namespace std;
string c;
int n;
void f(int l,int r)
{ 
	if(l>r)return;
	int mid=(l+r)/2;
  	if(l<r)
  	{ 
	  	f(l,mid);
    	f(mid+1,r);
  	}
  	int f=0,b=0,i=0;
  	for(int j=l;j<=r;j++)
   	{
	   	if(c[j]=='0')b++;
    	if(c[j]=='1')i++;
    	if(b>0&&i>0)break;
    }
  	if(b>0&&i==0)cout<<"B";
  	else if(b==0&&i>0)cout<<"I";
  	else if(b>0&&i>0)cout<<"F";
}
int main()
{ 
  	cin>>n>>c;
  	f(0,c.length()-1);
  	return 0;
}