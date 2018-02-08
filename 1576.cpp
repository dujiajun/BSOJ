#include<iostream>
using namespace std;
void ToDo(int n,char x,char y,char z)
{
     if(n==1){cout<<x<<"->"<<z<<endl;}
     else
     {
     ToDo(n-1,x,z,y);
     cout<<x<<"->"<<z<<endl;
     ToDo(n-1,y,x,z);
     }
}

int main()
{
    int n;
    cin>>n;
    ToDo(n,'A','B','C');
    return 0;
    }
