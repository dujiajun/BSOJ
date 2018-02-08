#include<iostream>
using namespace std;
 
int main()
{
    char a,b;
    cin>>a>>b;
    if(a=='S')//S 剪刀 R 石头 P 布 
    {
        if(b=='R') cout<<"Fall";//Win Equ Fall
        else if(b=='S') cout<<"Equ";
        else if(b=='P') cout<<"Win";
    }
    if(a=='R')//S 剪刀 R 石头 P 布 
    {
        if(b=='R') cout<<"Equ";//Win Equ Fall
        else if(b=='S') cout<<"Win";
        else if(b=='P') cout<<"Fall";
        }
    if(a=='P')//S 剪刀 R 石头 P 布 
    {
        if(b=='R') cout<<"Win";//Win Equ Fall
        else if(b=='S') cout<<"Fall";
        else if(b=='P') cout<<"Equ";
    }
    return 0;
}
