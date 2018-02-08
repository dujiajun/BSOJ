#include<iostream>
using namespace std;
 
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b) 
    {
        if(a>c) 
        {
        if(b>c) cout<<a<<" "<<b<<" "<<c;
        else cout<<a<<" "<<c<<" "<<b;
        }
        else 
        {
        cout<<c<<" "<<a<<" "<<b;
        }   
    }
    else //a<b
    { 
         if(b>c) 
        {
        if(a>c) cout<<b<<" "<<a<<" "<<c;//b>a>c
        else cout<<b<<" "<<c<<" "<<a;//b>c>a
        }
        else //b<c
        {
        cout<<c<<" "<<b<<" "<<a;
        }   
    }
    return 0;
}
