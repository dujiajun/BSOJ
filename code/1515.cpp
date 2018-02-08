#include<iostream>
#include<iomanip>
using namespace std;
const double pi = 3.1415926;
int main()
{
    int r;
    cin>>r;
    cout<<fixed<<setprecision(2)<<2*r*pi<<" "<<pi*r*r;
    return 0;
}