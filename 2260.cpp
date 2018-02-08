#include <iostream>
using namespace std;
int main()
{
    int n,l,j,a,b,minn=0,maxx=0,num;
    cin>>l>>n;
    for(int i=1;i<=n;i++) 
    {
    	cin>>j;
    	num=l+1-j;
    	a=min(num,j);b=max(num,j);
    	minn=max(minn,a);
    	maxx=max(maxx,b);
    }
    cout<<minn<<" "<<maxx<<endl;
}