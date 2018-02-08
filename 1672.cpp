#include<iostream>
using namespace std;
int n,m,x,y,l,c;
void ext(int a,int b,int &d,int &x,int &y)
{   
	int t;
    if(b==0){d=a;x=1;y=0;}
    else
	{ 
		ext(b,a%b,d,x,y);
        t=x;x=y;y=t-(a/b)*y;
	}
}
int main()
{  
	int a,b,c;
	cin>>x>>y>>m>>n>>l;
	if(m<n){swap(n,m);swap(x,y);}
	ext(m-n,l,c,a,b);
	if((y-x)%c!=0||m==n)cout<<"Impossible"<<endl;
	else cout<<((long long)a*(y-x)/c%(l/c)+l/c)%(l/c);
  	return 0;
}