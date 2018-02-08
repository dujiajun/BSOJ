#include<iostream>
#include<cstring>
using namespace std;
char c[400][400];
int m,n,mx=0,my=0,t;
const char p[6][8]={
"..+---+",
"./   /|",
"+---+ |",
"|   | +",
"|   |/.",
"+---+.."};					 
void draw(int x,int y)
{
	for(int i=y;i<=y+5;i++)
	for(int j=x;j<=x+6;j++)
	if(p[5-(i-y)][j-x]!='.')c[i][j]=p[5-(i-y)][j-x];
    my=max(my,y+5);mx=max(mx,x+6);
}
int main()
{
    cin>>m>>n;
	memset(c,'.',sizeof c);
    for(int i=1;i<=m;i++)
    for(int j=0;j<n;j++)
    {
        cin>>t;
        for(int k=0;k<t;k++)draw(1+(m-i)*2+j*4,1+(m-i)*2+k*3);
    }
	for(int i=my;i>=1;i--)
    {  
       for(int j=1;j<=mx;j++)cout<<c[i][j];
	   cout<<endl;
    }
    return 0;
}
/*
3 4
2 2 1 2
2 2 1 1
3 2 1 2
*/