#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cin>>x;
    if(x>0)
    {
        y=x+1;
    }
    else if(x<0)
    {
         y=x-1;
    }
    else 
    {
         y=0;
    }
    cout<<y;
    return 0;
}
