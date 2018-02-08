#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int s,t,w,j,a[27]={0};char c;
int main()
{
    cin>>s>>t>>w;
    for(int i=0;i<w;i++)
    {cin>>c;a[i]=c-'a'+1;}
    for(int k=1;k<=5;k++)
    {
    	for(j=w-1;j>0;j--)if(a[j]!=t-(w-j-1))break;
    	if(j==-1)break;
    	a[j]++;
    	for(j=j+1;j<w;j++)a[j]=a[j-1]+1;
    	for(j=0;j<w;j++)cout<<char(a[j]-1+'a');
    	cout<<endl;
    }
    return 0;
}