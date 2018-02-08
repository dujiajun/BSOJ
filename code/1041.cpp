#include<iostream>
using namespace std;

int Get(int n)
{
    int i,sum=0;
    for(i=1;i<=n;i++)sum+=n/i;
   	return sum;
}

int main()
{
	int t1,t2;
    cin>>t1>>t2;
    cout<<Get(t2)-Get(t1-1)<<endl;
    return 0;
}
