#include <iostream> 
#include<cstdio>
using namespace std; 
bool win(double n) 
{ 
     if(1<n&&n<=9)return true; 
     else if(n>9&&n<=18)return false; 
     else return win(n/18.0); 
} 
int main() 
{ 
    double n; 
    while(scanf("%lf",&n)!=EOF) 
    { 
         if(win(n)) 
         cout<<"Stan wins.\n"; 
         else 
         cout<<"Ollie wins.\n"; 
    } 
    return 0; 
}