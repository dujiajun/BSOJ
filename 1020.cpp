#include<iostream>
using namespace std;
int main()
{  
    int b[102],s=0,t=0,n,m,j,l,i;
    string a;
    cin>>n>>a>>m;
    l=a.length();
    for(i=0;i<=l-1;i++)
        if(a[i]>='A')s=s*n+(a[i]-'A'+10);
           else s=s*n+(a[i]-'0');
    while(s!=0)
    {  
        t++;
        b[t]=s%m;
        s=s/m;
    }
    for(j=t;j>=1;j--)
        if(b[j]>=10)cout<<char(b[j]+55);
        else cout<<b[j];
    return 0;
}
