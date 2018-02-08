#include<iostream>
using namespace std;
 
int main()
{
    double score;
    cin>>score;
    if(score>=86) cout<<"VERY GOOD";
    else if (score>=60) cout<<"GOOD";
    else cout<<"BAD";
    return 0;
}
