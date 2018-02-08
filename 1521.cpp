#include<iostream>
#include<iomanip>
using namespace std;
 
int main()
{
    double weight;
    double price;
    cin>>weight;
    if(weight<=10)
    {
        price=2.5;
    }
    else
    {
        price = 2.5+(weight-10)*1.5;
    }
    cout<<fixed<<setprecision(2)<<price;
    return 0;
}
