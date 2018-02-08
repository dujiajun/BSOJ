#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<n;i++)
    {
            if(n%i==0)
            {cout<<"NO";goto b;}
            else {continue;}
    }
    a:
    cout<<"YES";
    return 0;
    b:
    return 0;
}
